
#include <stdio.h>
#include <stdarg.h>

// variadic function
// you have to have at least one variadic function
void print_ints(int num, ...) // format string
{
	va_list args;

	va_start(args, num);

	for (int i=0; i < num; i++)
	{
		int value = va_arg(args, int);
		printf ("%d: %d\n", i, value);
	}
	va_end(args); // you can skip this for gcc or clang, but for compatibility it is better to keep it in
}


int main ()
{
	print_ints(3, 1, 2, 3);

	return (0);
}
