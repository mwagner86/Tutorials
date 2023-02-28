#include <unistd.h>

void	hidenp(char *str1, char *str2)
{
	while (*str1 != '\0')
	{
		while (*str1 != *str2 && *str2 != '\0')
			++str2;
		if (*str2 == '\0')
		{
			write(1, "0", 1);
			return;
		}
		++str2;
		++str1;
	}
	write(1, "1", 1);
}

int main (int argc, char *argv[])
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}