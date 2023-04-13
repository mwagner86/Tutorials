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