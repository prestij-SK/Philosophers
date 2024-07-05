#include "../header/philosophers.h"

void	philo_start(char **argv, int argc)
{
	size_t	i;
	t_PhiloData	data;

	if (!argv)
		error_exit("Not Valid Arguments!");
	philo_data_init(&data, argv, argc);
	philo_dinner_start(&data);
	i = 0;
	while (i < data.philo_num)
	{
		if (data.philo_arr[i].is_dead == B_TRUE)
		{
			philo_data_delete(&data);
			success_exit("Simulation Ended! With some unfortunate deaths...");
		}
		++i;
	}
	philo_data_delete(&data);
	success_exit("Simulation Ended! Everyone lived!");
}