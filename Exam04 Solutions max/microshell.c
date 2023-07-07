#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#define STDIN 		0
#define STDOUT 		1
#define STDERR 		2


#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5


typedef	struct s_base
{
	char 			**argv;
	int				size;
	int 			type;
	int 			fd[2];
	struct s_base 	*prev;
	struct s_base 	*next;
}	t_base;


int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}


char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	char *dup;

	if (!str)
		return (NULL);
	if(!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dup[size] = '\0';
	while (--size >= 0)
		dup[size] = str[size];
	return (dup);
}


void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}


void ft_lstadd_back(t_base **head, t_base *new_node)
{
	t_base *current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;	
	}
}


int size_argv(char **argv)
{
	int i = 0;
	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}


int check_end(char *av)
{
	if (!av)
		return (TYPE_END);
	if (strcmp(av, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(av, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}


int parser_argv(t_base **ptr, char **av)
{
	int 	size = size_argv(av);
	t_base *new;

	if (!(new = (t_base *)malloc(sizeof(t_base))))
		exit_fatal();
	if(!(new->argv = (char **)malloc(sizeof(char *) * size + 1)))
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	new->argv[size] = NULL;
	while (--size >= 0)
		new->argv[size] = ft_strdup(av[size]);
	new->type = check_end(av[new->size]);
	ft_lstadd_back(ptr, new);
	return (new->size);
}


void exec_cmd(t_base *tmp, char **env)
{
	pid_t pid;
	int status;
	int pipe_open = 0;

	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(tmp->argv[0], tmp->argv, env)) < 0)
			exit_execve(tmp->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(tmp->fd[STDOUT]);
			if (!tmp->next || tmp->type == TYPE_BREAK)
				close(tmp->fd[STDIN]);
		}
		if (tmp->prev && tmp->prev->type == TYPE_PIPE)
			close(tmp->prev->fd[STDIN]);
	}
}


void exec_cmds(t_base *ptr, char **env)
{
	t_base *tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp("cd", tmp->argv[0]) == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir(tmp->argv[1]))
				exit_cd_2(tmp->argv[1]);
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}


void free_all(t_base *ptr)
{
	t_base *tmp;
	int 	i = 0;

	while (ptr)
	{
		tmp = ptr->next;
		while (i < ptr->size)
		{
			free(ptr->argv[i]);
			i++;
		}
		free(ptr->argv);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}


int main (int argc, char *argv[], char *envp[])
{
	t_base *ptr = NULL;
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (strcmp(argv[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += parser_argv(&ptr, &argv[i]);
			if (!argv[i])
				break ;
			else
				i++;
		}
		if (ptr)
			exec_cmds(ptr, envp);
		free_all(ptr);		
	}
	return 0;
}