#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr >=10)
		ft_putnbr(nbr / 10);
	char c = (nbr % 10) + 48;
	write (1, &c, 1);
}

int main(void)
{
	int i;

	i = 1;
	while (i <= 100)
		{
			if ((i % 3 == 0) && (i % 5 == 0))
				write(1, "fizzbuzz", 8);
			else if (i % 3 == 0)
				write(1, "fizz", 4);
			else if (i % 5 == 0)
				write(1, "buzz", 4);
			else
				ft_putnbr(i);
			write(1, "\n", 1);
			i++;
		}
}