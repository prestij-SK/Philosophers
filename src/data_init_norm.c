#include "../header/philosophers.h"

void	philo_forks_data_init(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		error_exit("Initializing Issue!");
	if (!data->fork_arr)
		error_exit("Initializing Issue!");
	i = 0;
	while (i < data->philo_num)
	{
		mutex_operation_handle(data, &data->fork_arr[i].fork, INIT);
		data->fork_arr->fork_id = i;
		++i;
	}
}

// I think this is not needed, but will hold it just to go on with the tutorial
static int	set_philo_forks(t_PhiloData *data, t_Fork *fork_arr, int index)
{
	if (!data || !fork_arr)
		return (EXIT_FAILURE);
	data->philo_arr[index].first_fork = &fork_arr[(index + 1) % data->philo_num];
	data->philo_arr[index].second_fork = &fork_arr[index];
	if (index % 2 == 0)
	{
		data->philo_arr[index].first_fork = &fork_arr[index];
		data->philo_arr[index].second_fork = &fork_arr[(index + 1) % data->philo_num];
	}
	return (EXIT_SUCCESS);
}

void	philo_philosophers_data_init(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		error_exit("Initializing Issue!");
	if (!data->fork_arr || !data->philo_arr)
		error_exit("Initializing Issue!");
	i = 0;
	while (i < data->philo_num)
	{
		data->philo_arr[i].id = i + 1; // just so philosopher's id doesn't start from 0
		data->philo_arr[i].is_full = B_FALSE;
		data->philo_arr[i].meals_count = 0;
		data->philo_arr[i].main_data = data;
		if (set_philo_forks(data, data->fork_arr, i) == EXIT_FAILURE) // I think this is not needed, but will hold it just to go on with the tutorial
		{
			philo_data_delete(data);
			error_exit("Initializing Issue!");
		}
		++i;
	}
}