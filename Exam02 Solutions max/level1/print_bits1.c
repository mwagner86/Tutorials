#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (octet >= 0 && i)
	{
		(octet / i) ? write(1, "1", 1) : write(1, "0", 1);
		(octet / i) ? octet -= i : 0;
		i /= 2;
	}
}

void	print_bits2(unsigned char octet)
{
	int	i = 256;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
}

void	print_bits3(unsigned char octet)
{
	int i;

	i = 128;
	while (i > 0)
	{
		if (i & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

int		main(void)
{
	int n = 64;
	int i = 42;
	print_bits(n);
	write(1, "\n", 1);
	print_bits2(n);
    write(1, "\n", 1);
	print_bits3(n);
    write(1, "\n", 1);
	print_bits(i);
	write(1, "\n", 1);
	print_bits2(i);
    write(1, "\n", 1);
	print_bits3(i);
    write(1, "\n", 1);
}