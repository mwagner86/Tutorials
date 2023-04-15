#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}

int main(void)
{
	char s[] = "123Abhierstehttext";
	char num[] = "123Ab";

	int init = ft_strspn(s, num);
	int init2 = strspn(s, num);

	printf("init: %d\n", init);
	printf("init2: %d\n", init2);

	char *numcode = s + init;
	char *numcode2 = s + init2;

	printf("%s\n", numcode);
	printf("%s\n", numcode2);
}