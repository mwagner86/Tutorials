#include <unistd.h>

int	ft_atoi(char *str)
{
	int nbr;
	nbr = 0;

	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
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
	write(1, &c, 1);
}

int ft_isprime(int nbr)
{
	int i;
	i = 2;

	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int add_prime_sum(int nbr)
{
	int sum;
	int i;

	sum = 0;
	i = 2;

	while (i <= nbr)
	{
		if (ft_isprime(i) == 1)
			sum += i;
		++i;
	}
	return (sum);
}

int main(int argc, char *argv[])
{
	int nbr;
	if (argc == 2 && (nbr = ft_atoi(argv[1])))
		ft_putnbr(add_prime_sum(nbr));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
