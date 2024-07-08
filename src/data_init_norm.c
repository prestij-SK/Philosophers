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
		mutex_operation_handle(data, &data->lock_arr[i].fork, INIT);
		data->lock_arr->fork_id = i;
		++i;
	}
}

// This is important part to prevent deadlock.
// One way is:
// All philosophers take forks, first they take their fork (right) then neighbor's (left) fork.
// Only the last one takes fork alternetive way, first it takes (left) then (right).
// By this way, when they start eating, they first take left then right fork, but when finished, they first put right then left fork.
//
//
// Another way is:
// If philosopher is at Even index, first left then right fork is taken.
// If philosopher is at Odd index, first right then left fork is taken.
// By this way, when they start eating, they first take left then right fork, but when finished, they first put left then right fork.
static int	set_philo_forks(t_PhiloData *data, t_Fork *fork_arr, int index)
{
	if (!data || !fork_arr)
		return (EXIT_FAILURE);
	data->philo_arr[index].left_fork = &fork_arr[index];
	if (data->philo_num == 1) // if ther is only one philosopher, just quit
		return ;
	data->philo_arr[index].right_fork = &fork_arr[(index + 1) % data->philo_num];
	if (index + 1 == data->philo_num) // last philosopher will take forks alternative way
	{
		data->philo_arr[index].left_fork = &fork_arr[(index + 1) % data->philo_num];
		data->philo_arr[index].right_fork = &fork_arr[index];
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
		data->philo_arr[i].id = i;
		data->philo_arr[i].is_ready = B_FALSE;
		data->philo_arr[i].is_full = B_FALSE;
		data->philo_arr[i].is_dead = B_FALSE;
		data->philo_arr[i].must_stop = B_FALSE;
		data->philo_arr[i].meals_count = 0;
		data->philo_arr[i].last_meal_time = 0;
		data->philo_arr[i].timestamp = 0;
		data->philo_arr[i].main_data = data;
		data->philo_arr[i].lock = &data->lock_arr[i];
		if (set_philo_forks(data, data->fork_arr, i) == EXIT_FAILURE)
		{
			philo_data_delete(data);
			error_exit("Initializing Issue!");
		}
		++i;
	}
}