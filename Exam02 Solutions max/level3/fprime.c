#include <stdlib.h>
#include <stdio.h>

int	is_prime(int n)
{
	int i = 2;
	while (i < n)
	{
		if(n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int flag_first = 1;

	if (n == 1)
		printf("1");
	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (flag_first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			flag_first = 0;
			n = (n / factor);
		}
		else
			++factor;
	}
}

int main (int argc, char *argv[])
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}