#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	char *str;

	i = 0;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
				str[i] = str[i] + 1;
			else if ((str[i] == 'z') || (str[i] == 'Z'))
				str[i] = str[i] - 25;
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return(0);
}