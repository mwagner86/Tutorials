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

	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			flag = -1;
		i = i + 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += str[i] - 48;
		++i;
	}
	return (nbr * flag);
}

int main(int argc, char **argv)
{
	if(argc == 2)
		printf("ft_atoi(\"%s\") = int %d\n", argv[1], ft_atoi(argv[1]));
	return (0);
}