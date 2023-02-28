#include <unistd.h>

void	ft_rstr_capitalizer(char *str)
{
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
		{
			write (1, str, 1);
			++str;
		}
		while (*str != '\0' && *str != ' ' && *str != '\t')
		{
			if (*str >= 'a' && *str <= 'z' && (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\t'))
				*str = *str - 32;
			else if (*str >= 'A' && *str <= 'Z' && *(str + 1) != '\0' && *(str + 1) != ' ' && *(str + 1) != '\t')
				*str = *str + 32;
			write (1, str, 1);
			++str;
		}
	}
	write (1, "\n", 1);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			ft_rstr_capitalizer(argv[i]);
			++i;
		}
	}
	return (0);
}
