// compile with -g -pthread, f.e.:
// gcc -g -pthread threads.c -o threads

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine()
{
	x++;
	sleep(2);
	printf("Value of x: %d\n", x);
}

void *routine2()
{
	sleep(2);
	printf("Value of x: %d\n", x);
}

int main(int argc, char* argv[])
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1; // 0: thread got createad, if no thread was created, return 1
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
		return 2; // 0: thread got createad, if no thread was created, return 2
	if (pthread_join(t1, NULL))
	{
		return 3;
	}
	if (pthread_join(t2, NULL))
	{
		return 4;
	}
	return(0);
}