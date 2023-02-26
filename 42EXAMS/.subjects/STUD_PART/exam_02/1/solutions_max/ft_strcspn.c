#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
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
	return (i);
}

int main(void)
{
	char s[] = "ASDFGeerr49871312312312";
	char num[] = "123";

	int init = ft_strcspn(s, num);
	int init2 = strcspn(s, num);

	printf("init: %d\n", init);
	printf("init2: %d\n", init);

	char *numcode = s + init;
	char *numcode2 = s + init2;

	printf("%s\n", numcode);
	printf("%s\n", numcode2);
}

// int	main(void)
// {
// printf("%lu\n", ft_strcspn("test", "est"));
// printf("%lu\n", strcspn("test", "est"));
// printf("%lu\n", ft_strcspn("test", "f"));
// printf("%lu\n", strcspn("test", "f"));
// }