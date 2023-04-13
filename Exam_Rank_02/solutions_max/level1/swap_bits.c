#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
	unsigned char c;

	c = argv[1][0];
	write(1, &c, 1);
	write(1, "\n", 1);
	c = swap_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
	}
}
