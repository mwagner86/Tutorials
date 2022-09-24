#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>	// for fork(). linux specific.
#include <time.h>
#include <sys/wait.h>	// for wait(). the relevant lesson here. 

int main (int argc, char* argv[])
{
	int id = fork(); 
	// creates a child process. has the same memory, everything is copied over. same values.
	// child process gets process ID 0, parent process gets new process ID.
	int n;
	int i;

	if (id == 0)
	{
		n = 1;
	}
		else
		{
			n = 6;
		}
	if (id != 0)
	{
		wait(0); // is used to time the execution of the processes.
	}

		for (i = n; i < n + 5; i++)
		{
			printf("%d ", i);
			fflush(stdout);
		}
		printf("\n");
	if (id != 0) // to only use the linebreak in the child process.
	{
		printf("\n");
	}

	return 0;
}
