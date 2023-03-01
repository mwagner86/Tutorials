#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src)
{
	int i;
	char *dest;

	i = 0;

	while(src[i] != '\0')
	{
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return(NULL);
	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int main(void)
{
	printf("%s\n", ft_strdup("This is a test!"));
	printf("%s\n", strdup("This is a test!"));
}