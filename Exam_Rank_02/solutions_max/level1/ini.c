#include <unistd.h>

int check  (int c, char *str, int index)
{
	int i = 0;
	while (i < index || index == -1)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	char *s1;
	char *s2;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i] != '\0')
		{
			if ((check(s1[i], s1, i) == 1) && (check(s1[i], s2, -1) == 0))
				write (1, &s1[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}