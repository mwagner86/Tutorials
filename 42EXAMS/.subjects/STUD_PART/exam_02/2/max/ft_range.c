#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
	int *temp;
	int len;

	if (end < start)
		len = start - end;
	else
		len = end - start;
	temp = malloc(sizeof(int) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (len >= 0)
	{
		temp[len] = end;
		if (start > end)
			end++;
		else
			end--;
		len--;
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

	int *arr = ft_range(start, end);

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