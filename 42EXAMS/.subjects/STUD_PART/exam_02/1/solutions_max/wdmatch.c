#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	const char *str;

	str = argv[1];
	if (argc == 3)
	{
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		if (argv[1][i] == '\0')
			while (str[k])
			{
				write(1, &str[k], 1);
				k++;
			}
	}
	write(1, "\n", 1);
	return (0);
}
