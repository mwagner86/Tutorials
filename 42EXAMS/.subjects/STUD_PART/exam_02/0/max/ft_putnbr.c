#include <unistd.h>

void ft_putnbr (int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char c = (nbr % 10) + 48;
	write (1, &c, 1);
}


//tester

int main (void)
{
	int i;
	i = 0;

	while (i <= 100)
	{
		ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}