#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

# define UNDEFINED_VAL -1

typedef struct PhiloData
{
	size_t	philo_num;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	ssize_t	eat_limit;
	int		*p_arr;
	int		sim_start;
	int		sim_end;
}	t_Philosophers;

int	philo_start(char **argv, int argc);
int	philo_data_init(t_Philosophers *data, char **argv, int argc);

#endif