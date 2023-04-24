#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int len;
	int *array;
	int i = 0;

	if (end < start)
		len = start - end;
	else 
		len = end - start;
	array = malloc(sizeof(int) * len + 1);
	if (array == NULL)
		return(NULL);
	while (i <= len)
	{
		array[i] = end;
		if (start > end)
			end++;
		else
			end--;
		++i;
	}
	return (array);
}

int		absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		main(int argc, char **argv)
{
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);

	int *arr = ft_rrange(start, end);

	int i = 0;
	if (argc != 3)
		return 0;
	while (i < 1 + absolute_value(end - start))
	{
		printf("%d", arr[i]);
        if (i < 1 + absolute_value(end - start) - 1)
            printf(", ");
		++i;
	}
	printf("\n");
}