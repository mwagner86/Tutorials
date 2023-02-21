#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 10000; i++)
	// if number gets too high, data race occurs
	{
		pthread_mutex_lock(&mutex);
			{
				// wait until the lock is 0
				// this is implemented with the mutex functions in <pthread.h>
			}
		mails++;
		pthread_mutex_unlock(&mutex); // unlocks the thread. so next operation can be done without data race
		// read mails
		// increment
		// write mails
	}
}

int main(int argc, char *argv[])
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails); // data race prevented by the mutex function
	return(0);
}