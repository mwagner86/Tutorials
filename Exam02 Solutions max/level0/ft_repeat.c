#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int k;
	char *str;

	i = 0;
	k = 0;
	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			k = 1; // set to 1 to write chars that arent letters
			if (str[i] >= 'A' && str[i] <= 'Z')
				k = str[i] - 'A' + 1;
			if (str[i] >= 'a' && str[i] <= 'z') // no else to go into while loop if aren't letters
				k = str[i] - 'a' + 1;
			while (k >= 1)
			{
				write(1, &str[i], 1);
				k--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}