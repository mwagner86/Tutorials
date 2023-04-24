#include <unistd.h>

int main (int argc, char *argv[])
{
	int start;
	int end;
	int i = 0;
	int flag = 0;
	char *str;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
			i++;
		while (i >= 0)
		{
			while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
				i--;
			end = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			while (start <= end)
			{
				write(1, &str[start], 1);
				start++;
			}
			if (flag != 0)
				write (1, " ", 1);
		}
	}
	write (1, "\n", 1);
}