int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg);

int pthread_join(pthread_t thread, void **retval);

int pthread_detach(pthread_t thread);

gcc -fsanitize=thread -g threads.c && ./a.out
-check for data races


pthread_mutex_t    mutex;

Before we can use it, we first need to initialize it with the following function:

int pthread_mutex_init(pthread_mutex_t *mutex,
                        const pthread_mutexattr_t *mutexattr);

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

When we no longer need a mutex, we should destroy it with the following function:

int pthread_mutex_destroy(pthread_mutex_t *mutex);


 <sys/time.h>
int gettimeofday(struct timeval *tv, struct timezone *tz);


The usleep function in the <unistd.h> library allows us to stop the execution of the calling thread for a certain number of microseconds. Its prototype is:

int usleep(useconds_t usec);

Philo sleep function:

// Parameters of philo_sleep:
//     table = pointer to the variables of the "table", i.e. the program variables
//             like the flag indicating the end of the simulation
//     sleep_time = the time in milliseconds that the thread must be suspended for,
//                  typically time_to_sleep or time_to_eat
void	philo_sleep(t_table *table, time_t sleep_time)
{
	// Variable to measure when the philosopher thread must resume:
	time_t	wake_up;

	wake_up = get_time_in_ms() + sleep_time;
        // Loop as long as it's not wake up time:
	while (get_time_in_ms() < wake_up)
	{
		// Check if the simulation has stopped. If it has,
		// stop the loop (and this function) immediately
		// to continue thread execution:
		if (has_simulation_stopped(table))
			break ;
		// If the simulation is still going, usleep for a short time:
		usleep(100);
	}
}

typedef struct s_fork
{
	pthread_mutex_t	fork_lock;
	bool		in_use;
}	t_fork;


Time to think:
time_to_think = ((time_to_die - (get_time_in_ms() - philo->last_meal) - time_to_eat) / 2)


time_to_think = (time_to_die - (get_time_in_ms() - philo->last_meal) - time_to_eat) / 2
              = (   1000     - (       600       -       200       ) -     200    ) / 2
              = ( 1000 - 400 - 200 ) / 2
              = ( 600 - 200 ) / 2
              = 400 / 2
              = 200


There are some tools we can use to help us detect thread-related errors like possible data races, deadlocks and lock order violations:

The -fsanitize=thread -g flag we can add when compiling with gcc. The -g option displays the specific files and line numbers involved.
The thread error detection tool Helgrind that we can run our program with, like this: valgrind --tool=helgrind ./philo <args>.
DRD, another thread error detection tool that we can also run our program with, like this: valgrind --tool=drd ./philo <args>.


And as always, we can’t forget to check for memory leaks with -fsanitize=address and valgrind!