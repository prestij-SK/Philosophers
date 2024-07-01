#include "../header/philosophers.h"

static void	dinner_case_checks(t_PhiloData *data)
{
	if (!data)
		error_exit("Simulation Issue!");
	if (data->eat_limit == 0)
	{
		philo_data_delete(data);
		success_exit("Simulation Ended With Success!");
	}
	else if (data->philo_num == 1)
	{
		// TO DO
	}
}

static void	*dinner_simulation(void *p_data)
{
	t_Philo	*philo;

	philo = (t_Philo *)p_data;
	// wait_all_threads(); TO DO
	return (NULL);
}

void	philo_dinner_start(t_PhiloData *data)
{
	size_t	i;
	int	status;

	if (!data)
		error_exit("Simulation Issue!");
	dinner_case_checks(data);
	i = 0;
	while (i < data->philo_num)
	{
		status = thread_operation_handle(&data->philo_arr[i].thread_id, dinner_simulation, &data->philo_arr[i], CREATE);
		thread_error_handle(data, status, CREATE);
		++i;
	}
}