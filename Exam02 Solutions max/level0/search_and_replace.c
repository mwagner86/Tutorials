#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	char *str;

	i = 0;
	if (argc == 4)
	{
		str = argv[1];
		if(((argv[2][0] >= 'a' && argv[2][0] <= 'z') || (argv [2][0] >= 'A' && argv[2][0] <= 'Z')) && argv[2][1] == '\0')
			if (((argv[3][0] >= 'a' && argv [3][0] <= 'z') || (argv[3][0] >= 'A' && argv[3][0] <= 'Z')) && argv[3][1] == '\0')
			{
				while(str[i] != '\0')
				{
					if (str[i] == argv[2][0])
						str[i] = argv[3][0];
					write(1, &str[i], 1);
					i++;
				}
			}
	}
	write(1, "\n", 1);
}
