#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int g_exit_status;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_pwd(void);

int main(void)
{
	ft_pwd();
	return 0;
}

void	ft_pwd(void)
{
	char	*str;

	str = ft_calloc(1000, sizeof(char));
	printf("%s\n", getcwd(str, 500));
	free(str);
	g_exit_status = 0;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	s = ptr;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	calloc = malloc(count * size);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, count * size);
	return (calloc);
}