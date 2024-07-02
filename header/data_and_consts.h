#ifndef DATA_AND_CONSTS
# define DATA_AND_CONSTS

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

/*** CONSTANTS ***/
# define MAX_NUMBER_COUNT 19
# define MILLISECOND_VALUE 1e3
# define MIN_TIME_LIMIT 6e4
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
	FORK_PICK,
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
	size_t		id;
	size_t		meals_count; // how many times philosopher eat
	int			is_full; // if philosopher's 'meals_counter' is reached to maximum allowed (5th argument) meanls
	int			is_dead;
	size_t		last_meal_time; // time passed from last meal
	t_Fork		*left_fork;
	t_Fork		*right_fork;
	pthread_t	thread; // philosopher is a thread
	t_PhiloData	*main_data;
}	t_Philo;

struct	PhilosophersData
{
	size_t			philo_num;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	ssize_t			eat_limit;
	t_Philo			*philo_arr;
	t_Fork			*fork_arr;
	// pthread_mutex_t	data_mutex; // To avoid races when reading from main data
	int				simulate_start;
	int				simulate_end;
	int				is_threads_ready; // Used to synchronize Philosophers
};

#endif