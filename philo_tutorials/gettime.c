#include <sys/time.h>
#include <stdio.h>

time_t	get_time_in_ms(void)
{
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}



int main() 
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);

	printf("seconds : %ld\nmicro seconds : %ld",
    current_time.tv_sec, current_time.tv_usec);

	printf("\n%ld", get_time_in_ms());

  return 0;
}