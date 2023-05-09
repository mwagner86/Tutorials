#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t k = 0;

	while (s[i] != '\0')
	{
		while (reject[k] != '\0')
		{
			if (reject[k] == s[i])
				return (i);
			k++;
		}
		k = 0;
		i++;
	}
	return(i);
}

int main(void)
{
	char a[] = "asdadkakadsgsd23124152453453490534906";
	char b[] = "12345";

	size_t init = ft_strcspn(a, b);
	size_t init2 = strcspn(a, b);

	printf("init: %zu\n", init);
	printf("init2: %zu\n", init2);
}
