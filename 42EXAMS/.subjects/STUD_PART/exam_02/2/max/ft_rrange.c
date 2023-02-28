#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int *temp;
	int i = 0;
	int len = end - start + 1;

	if (start > end)
		return (ft_rrange(end, start));
	temp = malloc(sizeof(int) * len);
	if (temp)
	{
		while (i < len)
		{
			temp[i] = start;
			start++;
			i++;
		}
	}
	return (temp);
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