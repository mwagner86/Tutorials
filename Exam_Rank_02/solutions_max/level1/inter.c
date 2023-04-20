#include <unistd.h>

/* int main(int argc, char *argv[])
{
	int i;
	int j;
	int k;
	char *s1;
	char *s2;

	i = 0;
	j = 0;
	k = 0;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i] != '\0')
		{	
			k = 0;
			while(s2[k] != '\0')
			{
				if(s1[i] == s2[k])
				{
					j = 0;
					while (s1[j] != s1[i])
						j++;
					if (j == i)
					{
						j = 0;
						while (s2[j] != s2[k])
							j++;
						if (j == k)
							write(1, &s1[i], 1);
					}				
				}
				k++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}


// come on....
 */

int	inter(char *str, char c, int len)
{
	int	i = 0;

	while (str[i] && (i < len || len == -1))
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);

}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!inter(argv[1], argv[1][i], i) && inter(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}