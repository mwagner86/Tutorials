#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i;

	i = 128; // 10000000 in binary
	while (i > 0)
	{
		if (i & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1; // 10000000 becomes 01000000 becomes 00100000 etc.
	}
}

void print_bits2(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


/* int  main(void)
{
	print_bits(255);
	printf("\n");
	print_bits(2);
	printf("\n");
	print_bits2(255);
	printf("\n");
	print_bits2(2);
	printf("\n");
	return(0);
} */

unsigned char	reverse_bits2(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}

int  main(void)
{
	print_bits(42);
	printf("\n");
	print_bits(reverse_bits2(42));
	printf("\n");
	print_bits(swap_bits(42));
	printf("\n");
}
