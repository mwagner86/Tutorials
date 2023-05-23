#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

 # ifndef BUFFER_SIZE
 #define BUFFER_SIZE 42
 # endif

char *get_next_line(int fd);

int main (void)
{
	int fd;
	char *line;

	fd = open("gnl_try.c", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *remains, char *buffer)
{
	char *array;
	unsigned int size;
	int i = 0;
	int j = 0;

	if(!remains && !buffer)
		return (NULL);
	size = ft_strlen(remains) + ft_strlen(buffer);
	if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (remains)
	{
		while (remains[i])
			array[j++] = remains[i++];
		i = 0;
	}
	while (buffer[i])
		array[j++] = buffer[i++];
	array[size] = '\0';
	free (remains);
	return (array);
}

int ft_strchr(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_push_line (char *remains)
{
	int i = 0;
	char *array;

	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\n')
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		array[i] = '\n';
		i++;
	}
	array[i] = '\0';
	return (array);
}

char *ft_cut_next_line(char *remains)
{
	int i = 0;
	int j = 0;
	char *array;

	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while (remains[i])
	{
		array[j] = remains[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free (remains);
	return(array);
}

char *get_next_line(int fd)
{
	static char *remains;
	char *line;
	int count = 1;
	char buffer[BUFFER_SIZE + 1];
	buffer[0] = '\0';

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE + 1 <= 0)
		return (NULL);
	
	while (!ft_strchr(buffer) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1))
			return (NULL);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	line = ft_push_line(remains);
	remains = ft_cut_next_line(remains);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
