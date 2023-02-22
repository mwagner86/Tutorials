#include <stdlib.h>
#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int res;

	if (len == 0)
		return (0);
	res = tab[0];
	for (unsigned int i = 0; i < len; i = i + 1)
	{
		if (res < tab[i])
			res = tab[i];
	}
	return (res);
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return(0);
    int *tab = malloc(sizeof(int) * (argc - 1));
    
    printf("max( {");
    for (unsigned int i = 2; i < argc; i++)
    {
        printf("%s", argv[i]);
        if (i != argc - 1)
            printf(";");
        tab[i - 2] = atoi(argv[i]);
    }
    printf("} , %s) = %d\n", argv[1], max(tab, atoi(argv[1])));
    // printf("max(\"%s\") = %d\n", argv[1], is_power_of_2(atoi(argv[1])));
    return(0);
}
