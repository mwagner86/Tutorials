#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	const char *haystack;
	const char *str;

	str = argv[1];
	haystack = argv[2];
	if (argc == 3)
	{
		while (haystack[j] != '\0')
		{
			if (haystack[j] == str[i])
				i++;
			j++;
		}
		if (str[i] == '\0')
			while (str[k] != '\0')
			{
				write(1, &str[k], 1);
				k++;
			}
	}
	write(1, "\n", 1);
	return (0);
}
