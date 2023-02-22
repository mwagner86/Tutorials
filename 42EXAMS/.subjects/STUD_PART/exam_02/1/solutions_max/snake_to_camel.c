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
			if (str[i] == '_')
			{
				i++;
				str[i] -=32;
			}
			write(1, &str[i],1);
			i++;
		}
	}
	write(1,"\n",1);
}
