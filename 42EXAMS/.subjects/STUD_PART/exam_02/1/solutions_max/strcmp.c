#include <stdio.h>
#include <string.h>


int ft_strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


int main(void)
{
	printf("Original vs Clone: <%d> <%d>", strcmp("hello World", "hello world") , ft_strcmp("hello World", "hello world"));
	printf("\nOriginal vs Clone: <%d> <%d>", strcmp("hello World", "") , ft_strcmp("hello World", ""));
	printf("\nOriginal vs Clone: <%d> <%d>", strcmp("hello world", "hello world") , ft_strcmp("hello world", "hello world"));
}