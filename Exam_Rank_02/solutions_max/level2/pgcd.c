#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int n;
	n = b;

	while (n > 0)
	{
		if ( a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}	
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		pgcd(atoi(argv[1]), atoi(argv[2]));
	}
	printf("\n");
	return (0);
}
