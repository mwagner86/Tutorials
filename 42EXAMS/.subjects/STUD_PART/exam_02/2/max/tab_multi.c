#include <unistd.h>

int	ft_atoi(char *str)
{
	int nbr;
	nbr = 0;

	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10;
		nbr += *str - 48;
		++str;
	}
	return (nbr);
}

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char c = (nbr % 10) + 48;
	write (1, &c, 1);
}

void	tab_multi(char *str)
{
	int i;
	int nbr;

	i = 1;
	nbr = ft_atoi(str);

	while (i <= 9)
	{
		ft_putnbr (i);
		write (1, " x ", 3);
		ft_putnbr (nbr);
		write (1, " = ", 3);
		ft_putnbr (i * nbr);
		write (1, "\n", 1);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		tab_multi(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
