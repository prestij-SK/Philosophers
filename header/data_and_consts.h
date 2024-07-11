#ifndef DATA_AND_CONSTS
# define DATA_AND_CONSTS

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

/*** CONSTANTS ***/
# define MAX_NUMBER_COUNT 19
# define MIN_MILLISECOND_LIMIT 60
# define UNDEFINED_VAL -1

/*** STATUSES ***/
typedef enum Statuses
{
	B_FALSE = 0,
	B_TRUE = 1,
	VALID,
	NOT_VALID,
}	t_Status;

typedef enum PThreadOperationCode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_PThreadOpCode;

typedef enum PhilosopherStatus
{
	LEFT_FORK,
	RIGHT_FORK,
	THINK,
	EAT,
	SLEEP,
	DEAD,
}	t_PhiloStatus;

/*** STRUCTS ***/
typedef struct PhilosophersData t_PhiloData;

typedef struct Fork
{
	pthread_mutex_t	fork;
	size_t			fork_id;
}	t_Fork;

typedef struct Philosopher
{
	size_t			id;
	int				is_ready; // This will be used to see if all threads are ready (synchronized)
	int				is_full; // if philosopher's 'meals_counter' is reached to maximum allowed (5th argument) meanls
	int				is_dead;
	int				must_stop;
	ssize_t			meals_count; // how many times philosopher eat
	size_t			last_meal_time; // time passed from last meal
	t_Fork			*lock;
	t_Fork			*left_fork;
	t_Fork			*right_fork;
	pthread_t		thread; // philosopher is a thread
	pthread_mutex_t	philo_mtx;
	t_PhiloData		*main_data;
}	t_Philo;

struct	PhilosophersData
{
	size_t			philo_num; // number of philosophers
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	ssize_t			eat_limit;
	size_t			start_time;
	int				stop_simulation; // Will mean that all philosophers (threads) must stop their work
	t_Philo			*philo_arr;
	t_Fork			*fork_arr;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	getter_mtx;
	pthread_mutex_t	setter_mtx;
	pthread_mutex_t	iterator_mtx;
};

#endif