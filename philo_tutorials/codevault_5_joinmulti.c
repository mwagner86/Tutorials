#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;

void *roll_dice()
{
	pthread_mutex_lock(&mutex);
	int value = (rand() % 6) + 1;
	pthread_mutex_unlock(&mutex);
	int *result = malloc(sizeof(int));
	*result = value;
	// printf("%d\n", value);
	// printf("Thread result memory address result: %p\n", result);
	return (void*) result;
}

int main(int argc, char *argv[])
{
	int *res;
	srand(time(NULL));
	pthread_t th[8];
	int i;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 8; i++)
	{
		if (pthread_create(th + i, NULL, &roll_dice, NULL) !=0)
		{
			perror("Failed to create thread");
			return 1;
		}
		printf("Thread %d has started\n", i);
	}

	for (i = 0; i < 8; i++)
	{
		if (pthread_join(th[i], (void**) &res) != 0)
			return 2;
		printf("Thread %d has finished execution\n", i);
		printf("Result: %d\n", *res);
		free(res);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
