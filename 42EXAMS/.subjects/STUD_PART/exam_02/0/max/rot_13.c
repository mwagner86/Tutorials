#include <unistd.h>

int main (int argc, char *argv[])
{
	int i;
	char *str;

	i = 0;
	if(argc == 2)
	{
		str = argv[1];
		while(str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A') && (str[i] <= 'M'))
				str[i] = str[i] + 13;

			else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
				str[i] = str[i] - 13;

			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
