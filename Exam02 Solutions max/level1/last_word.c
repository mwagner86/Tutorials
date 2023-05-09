#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	char *str;

	i = 0;

	if (argc == 2)
	{
		str = argv[1];
		while(str[i] != '\0')
			i++;
		i--;
		while((str[i] == ' ' || str[i] == '\t') && i != 0)
			i--;
		while((str[i] != ' ' || str[i] == '\t') && i != 0)
			i--;
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}