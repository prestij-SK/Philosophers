#include "../header/philosophers.h"

void	philo_start(char **argv, int argc)
{
	t_PhiloData	data;

	if (!argv)
		error_exit("Not Valid Arguments!");
	philo_data_init(&data, argv, argc);
	// printf("\n%zu %zu %zu %zu %zu\n", data.philo_num, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.eat_limit);
}