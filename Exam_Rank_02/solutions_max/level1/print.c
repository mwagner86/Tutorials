#include <stdio.h>

int main(void)
{
	int i;
	i = 0;

	while (i < 255)
	{
		printf("%d %c \n", i,i);
		i++;
	}
	return(0);
}
