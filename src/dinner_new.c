#include "../header/philosophers.h"

static void	dinner_case_checks(t_PhiloData *data)
{
	if (!data)
		error_exit("Simulation Issue!");
	if (data->eat_limit == 0)
	{
		philo_data_delete(data);
		success_exit("Simulation Ended!");
	}
	else if (data->philo_num == 1)
	{
		// TO DO
	}
}

void	*observer(void *m_data)
{
	size_t	i;
	t_PhiloData	*data;

	if (!m_data)
		error_exit("Simulation Issue!");
	data = (t_PhiloData *)m_data;
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
				return (NULL);
			}
			++i;
		}
	}
	return (NULL);
}

static void	*time_to_feast(void *p_data)
{
	t_Philo	*philo;

	philo = (t_Philo *)p_data;
	if (philo->id % 2 == 0)
		milisecond_sleep(philo->main_data->time_to_eat);
	while (B_TRUE)
	{
		if (philo->must_stop == B_TRUE)
			break ;
		if (is_current_philo_dead(philo) == B_TRUE)
			philo->is_dead = B_TRUE;
		if (philo->is_dead == B_TRUE)
		{
			print_philo_action(philo, DEAD);
			break ;
		}
		if (philo_pickup_fork(philo) == B_FALSE)
			break ;
		if (philo_eat(philo) == B_FALSE)
			break ;
		if (philo_sleep(philo) == B_FALSE)
			break ;
		if (philo_think(philo) == B_FALSE)
			break ;
	}
	return (NULL);
}

// static void	dinner_simulation(t_PhiloData *data)
// {
// 	size_t	i;
// 	int		status;

// 	if (!data)
// 		error_exit("Simulation Issue!");
// 	i = 0;
// 	while (i < data->philo_num)
// 	{
// 		data->philo_arr[i].last_meal_time = get_time();
// 		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, &data->philo_arr[i], CREATE);
// 		thread_error_handle(data, status, CREATE);
// 		++i;
// 	}
// }

void	philo_dinner_start(t_PhiloData *data)
{
	int		status;
	size_t	i;

	if (!data)
		error_exit("Simulation Issue!");
	// printf("p_num: %zu\n", data->philo_num);
	// printf("t_die: %zu\n", data->time_to_die);
	// printf("t_eat: %zu\n", data->time_to_eat);
	// printf("t_sleep: %zu\n", data->time_to_sleep);
	// printf("p_num: %zd\n", data->eat_limit);
	dinner_case_checks(data);
	status = thread_operation_handle(&data->obs, observer, data, CREATE);
	thread_error_handle(data, status, CREATE);
	usleep(1e3);
	i = 0;
	while (i < data->philo_num)
	{
		data->philo_arr[i].last_meal_time = get_time();
		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, &data->philo_arr[i], CREATE);
		thread_error_handle(data, status, CREATE);
		++i;
	}
	// while(B_TRUE)
	// {
	// 	i = 0;
	// 	if (check_all_full(data) == B_TRUE)
	// 			break ;
	// 	while (i < data->philo_num)
	// 	{
	// 		if (data->philo_arr[i].is_dead == B_TRUE)
	// 		{
	// 			i = 0;
	// 			while (i < data->philo_num)
	// 			{
	// 				data->philo_arr[i].must_stop = B_TRUE;
	// 				++i;
	// 			}
	// 			philo_data_delete(data);
	// 			success_exit("Simulation Ended!");
	// 		}
	// 		++i;
	// 	}
	// }
	status = thread_operation_handle(&data->obs, observer, data, JOIN);
	thread_error_handle(data, status, JOIN);
	i = 0;
	while (i < data->philo_num)
	{
		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, data, JOIN);
		thread_error_handle(data, status, JOIN);
		++i;
	}
	philo_data_delete(data);
	success_exit("Simulation Ended!");
}