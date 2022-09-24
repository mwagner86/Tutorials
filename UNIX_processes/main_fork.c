#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // for fork. linux specific.

int main (int argc, char* argv[])
{
	int id = fork();
	if (id != 0) // the child process, which got the ID 0 wont get forked, only the parent process with an ID different than 0.
	{
	fork();
	}

	printf("Hello world\n");
/* 	if (id == 0)
	{
		printf("Hello from child process\n");
	}
	else
	{
		printf("Hello from the main process\n");
	} */
	return 0;
}