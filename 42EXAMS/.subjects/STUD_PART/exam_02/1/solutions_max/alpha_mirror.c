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
			{
				if(str[i] >= 'a' && str[i] <= 'z')
					str[i] = 219 - str[i];
				else if(str[i] >= 'A' && str[i] <= 'Z')
					str[i] = 155 - str[i];
				write(1, &str[i], 1);
				i++;
			}
	}
	write (1, "\n", 1);
}