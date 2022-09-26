#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	int	id1;
	int	id2;

	id1 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("we are process y\n");
		}
		else
		{
			printf ("we are process x\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf ("we are process z\n");
		}
		else
		{
			printf ("we are the parent process!\n");
		}
	}
	while(wait(NULL) != -1 || errno != ECHILD);
		printf("Waited for a child to finish\n");
	return 0;
}
