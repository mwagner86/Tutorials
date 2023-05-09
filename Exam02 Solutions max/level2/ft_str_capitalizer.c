#include <unistd.h>

void	ft_str_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			++str;
		}
		if (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - 32;
			write(1, str, 1);
			++str;
		}
		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if(*str >= 'A' && *str <= 'Z')
				*str = *str + 32;
			write (1, str, 1);
			++str;
		}	
	}
	write (1, "\n", 1);		
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "\n", 1);
	int i = 1;
	while (i < argc)
	{
		ft_str_capitalizer(argv[i]);
		++i;
	}
	return (0);
}
