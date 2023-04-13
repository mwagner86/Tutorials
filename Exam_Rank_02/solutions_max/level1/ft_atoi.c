#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
	int nbr;
	int flag;
	int i;

	nbr = 0;
	flag = 1;
	i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += str[i] - 48;
		++i;
	}
	return (nbr * flag);
}

int main(int argc, char **argv)
{
	char *str;
	if (argc == 2)
	{
		str = argv[1]; 
		printf("ft_atoi(%s) = int %d\n", argv[1], ft_atoi(str));
		printf("atoi(%s) = int %d\n", argv[1], atoi(str));
	}
	if (argc != 2)
		printf("\n");
	return (0);
}
