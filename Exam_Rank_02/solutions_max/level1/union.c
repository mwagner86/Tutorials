#include <unistd.h>

int check(int c, char *str, int index)
{
	int i;
	i = 0;

	while(i < index)
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
	int j = 0;
	int k = 0;
	char *s1;
	char *s2;
	
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i] != '\0')
			i++;
		while (s2[j] != '\0')
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		i--;
		while (k < i)
		{
			if (check(s1[k], s1, k) == 1)
				write(1, &s1[k], 1);
			k++;
		}
	}
	write (1, "\n", 1);
}
