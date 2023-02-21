#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void *routine()
{
	for (int i = 0; i < 10; i++) // if number gets too high, data race occurs
	{
		mails++;
		// read mails
		// increment
		// write mails
	}
}

int main(int argc, char *argv[])
{
	pthread_t p1, p2;
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;
	printf("Number of mails: %d\n", mails); // you would expect 20000 but since it's a race condition, the number will not be correct
	return(0);
}