#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	unsigned char last;
	unsigned char reversed;

	i = 0;
	while (i < 7)
	{
		last = octet & 1;
		octet >>= 1;
		reversed += last;
		reversed <<= 1;
		i++;
	}
	return (reversed);
}

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