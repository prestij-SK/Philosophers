#include "../header/philosophers.h"

// Actually no point to create a function for one philo only,
// but the subject wants to create as much thread as much philos there are.
// So just simple no sense logic for one philo thread
static void	*one_philo(void *p_data)
{
	t_Philo	*philo;

	if (!p_data)
		return (NULL);
	philo = (t_Philo *)p_data;
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, LOCK);
	print_philo_action(philo, LEFT_FORK);
	milisecond_sleep(philo->main_data->time_to_die);
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
	philo->is_dead = B_TRUE;
	print_philo_action(philo, DEAD);
	return (NULL);
}

static void	dinner_case_checks(t_PhiloData *data)
{
	int	status;

	if (!data)
		error_exit("Simulation Issue!");
	if (data->eat_limit == 0)
	{
		philo_data_delete(data);
		success_exit("Simulation Ended!");
	}
	else if (data->philo_num == 1)
	{
		status = thread_operation_handle(&data->philo_arr[0].thread, one_philo, &data->philo_arr[0], CREATE);
		thread_error_handle(data, status, CREATE);
		while (data->philo_arr[0].is_dead != B_TRUE)
		{}
		status = thread_operation_handle(&data->philo_arr[0].thread, one_philo, &data->philo_arr[0], JOIN);
		thread_error_handle(data, status, JOIN);
		philo_data_delete(data);
		success_exit("Simulation Ended!");
	}
}

// void	*observer(void *m_data)
// {
// 	size_t	i;
// 	t_PhiloData	*data;

// 	if (!m_data)
// 		error_exit("Simulation Issue!");
// 	data = (t_PhiloData *)m_data;
// 	while(B_TRUE)
// 	{
// 		i = 0;
// 		if (check_all_full(data) == B_TRUE)
// 				break ;
// 		while (i < data->philo_num)
// 		{
// 			if (data->philo_arr[i].is_dead == B_TRUE)
// 			{
// 				i = 0;
// 				while (i < data->philo_num)
// 				{
// 					data->philo_arr[i].must_stop = B_TRUE;
// 					++i;
// 				}
// 				return (NULL);
// 			}
// 			++i;
// 		}
// 	}
// 	return (NULL);
// }

static void	*time_to_feast(void *p_data)
{
	t_Philo	*philo;

	if (!p_data)
		return (NULL);
	philo = (t_Philo *)p_data;
	philo->is_ready = B_TRUE;
	wait_all_threads(philo->main_data);
	if (philo->id % 2 == 0)
		milisecond_sleep(philo->main_data->time_to_eat);
	while (B_TRUE)
	{
		if (philo_action_chain(philo) == B_FALSE)
			break ;
	}
	return (NULL);
}

void	observer(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		return ;
	while(B_TRUE)
	{
		i = 0;
		if (check_all_full(data) == B_TRUE)
				break ;
		while (i < data->philo_num)
		{
			if (data->philo_arr[i].is_dead == B_TRUE)
			{
				i = 0;
				while (i < data->philo_num)
				{
					data->philo_arr[i].must_stop = B_TRUE;
					++i;
				}
				return ;
			}
			++i;
		}
	}
}

void	philo_dinner_start(t_PhiloData *data)
{
	int		status;
	size_t	i;

	if (!data)
		error_exit("Simulation Issue!");
	dinner_case_checks(data);
	// status = thread_operation_handle(&data->obs, observer, data, CREATE);
	// thread_error_handle(data, status, CREATE);
	// usleep(1e3);
	i = 0;
	while (i < data->philo_num)
	{
		data->philo_arr[i].last_meal_time = get_time();
		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, &data->philo_arr[i], CREATE);
		thread_error_handle(data, status, CREATE);
		++i;
	}
	observer(data);
	// status = thread_operation_handle(&data->obs, observer, data, JOIN);
	// thread_error_handle(data, status, JOIN);
	i = 0;
	while (i < data->philo_num)
	{
		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, data, JOIN);
		thread_error_handle(data, status, JOIN);
		++i;
	}
}