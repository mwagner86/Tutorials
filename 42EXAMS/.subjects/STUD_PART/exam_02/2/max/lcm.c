#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	if (a == 0 || b == 0)
		return 0;
	
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		++lcm;

	}

}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return 0;
	unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[2]);
	printf("%d\n", lcm(a,b));
}