#include <unistd.h>

int ft_word_len(char *str)
{
	int i = 0;

	while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void ft_epur_str(char *str)
{
	int flag_first_word = 1;
	int word_len;
	
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		word_len = ft_word_len(str);
		if (word_len > 0 && flag_first_word == 0)
			write(1, " ", 1);
		flag_first_word = 0;
		write(1, str, word_len);
		str = str + word_len;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		ft_epur_str(argv[1]);
	write (1, "\n", 1);
	return (0);
}

// another, arguably better, solution:

#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	int flg = 0;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}