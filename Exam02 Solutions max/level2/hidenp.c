#include <unistd.h>

/* void	hidenp(char *str1, char *str2)
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
} */

// better solution

int main (int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	char *s1;
	char *s2;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i] && s2[j])
		{
			if (s2[j] == s1[i])
				i++;
			j++;
		}
		if (s1[i] == '\0')
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
	write (1, "\n", 1);
	return (0);
}