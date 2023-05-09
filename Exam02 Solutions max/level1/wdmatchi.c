#include <unistd.h>

int main (int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	char *needle;
	char *haystack;

	if (argc == 3)
	{
		needle = argv[1];
		haystack = argv[2];
		while (haystack[j] != '\0')
		{
			if (haystack[j] == needle[i])
				i++;
			j++;
		}
		if (needle[i] == '\0')
		{
			i = 0;
			while (needle[i] != '\0')
			{
				write (1, &needle[i], 1);
				i++;
			} 
		}
	}
	write (1, "\n", 1);
	return (0);
}