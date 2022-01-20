#include <stdio.h>
#include <stdarg.h>

// Add all the arguments and return sum until zero(0) appears.

int	SumArgs(int first_arg, ...)
{
	int i;
	int sum;

	sum = 0;
	va_list args;
	va_start(args, first_arg);

	for (i = first_arg, i > 0; i = va_arg(args, int);)
	{
		sum += i;
	}

	va_end(args);

	return (sum);
}

int main(void)
{
	printf("%d\n",SumArgs(10,10,15,25,35,64,99,123,423,22,0));
	return (0);
}
