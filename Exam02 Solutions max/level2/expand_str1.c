#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int flag = 0;
	char *str;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] != '\0')
		{
			if (str[i] == ' ' || str[i] == '\t')
				flag = 1;
			if (!(str[i] == ' ' || str[i] == '\t'))
			{
				if (flag == 1)
					write (1, "   ", 3);
				flag = 0;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}