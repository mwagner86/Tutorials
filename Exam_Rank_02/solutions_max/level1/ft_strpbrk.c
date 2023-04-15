#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s, const char *accept)
{
	int i = 0;
	
	if (!s || !accept)
	{
		return (0);
	}
	while(*s)
	{
		i = 0;
	   	while(accept[i])
		{
			if(*s == accept[i])
				return (char *) s;
			i++;
		}
		s++;	
	}
	return (0);
}

int main(void)
{
	char s1[] = "hierstehttext";
	char s2[] = "";

	char *init = ft_strpbrk(s1, s2);
	char *init2 = strpbrk(s1, s2);

	printf("init: %s\n", init);
	printf("init2: %s\n", init2);
}