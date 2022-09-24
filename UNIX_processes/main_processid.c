#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int id = fork();
	if (id == 0)
			sleep(1);
		printf("current ID: %d, parent ID %d\n",
	getpid(), getppid());

	int res = wait(NULL); // result of the return value of wait(). -1 is error(no child process to wait for).
	if (res == -1)
	{
		printf("No children to wait for\n");
	}
		else
		{
			printf("%d finished execution\n", res);
		}
		wait(NULL);

	return 0;
}
