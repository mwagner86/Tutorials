// command line arguments

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[]) // int argument count, array of strings argument vector.
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	int result = 1;
	for (i = 1; i < argc; i++)
	{
		int x = strtol(argv[i], NULL, 10);
		result = result * x;
	}
	printf("Multiplication result is %d\n", result);
	return (0);
}
