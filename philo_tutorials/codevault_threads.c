// compile with -g -pthread, f.e.:
// gcc -g -pthread threads.c -o threads

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *routine(void *arg)
{
	printf("test from threads\n");
	sleep(3);
	printf("Ending thread\n");
}

int main(int argc, char* argv[])
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1; // 0: thread got createad, if no thread was created, return 1
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2; // 0: thread got createad, if no thread was created, return 2
	pthread_join(t1, NULL); // wait for the thread t1 to finish
	pthread_join(t2, NULL); // wait for the thread t2 to finish
	return(0);
}