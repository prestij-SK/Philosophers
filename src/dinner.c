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
	philo->main_data->start_time = get_time();
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, LOCK);
	print_philo_action(philo, LEFT_FORK);
	milisecond_sleep(get_time_to_die(philo->main_data));
	print_philo_action(philo, DEAD);
	set_is_dead(philo, B_TRUE);
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
	return (NULL);
}

static void	dinner_case_checks(t_PhiloData *data)
{
	if (!data)
		error_exit("Simulation Issue!");
	if (data->eat_limit == 0)
	{
		philo_data_delete(data);
		success_exit("Simulation Ended! Nothing to eat");
	}
	else if (data->philo_num == 1)
	{
		thread_operation_handle(&data->philo_arr[0], &data->philo_arr[0].thread, one_philo, CREATE);
		while (!get_is_dead(&data->philo_arr[0]))
		{}
		thread_operation_handle(&data->philo_arr[0], &data->philo_arr[0].thread, one_philo, JOIN);
		philo_data_delete(data);
		success_exit("Simulation Ended! That one bro died...");
	}
}

static void	*time_to_feast(void *p_data)
{
	t_Philo	*philo;

	if (!p_data)
		return (NULL);
	philo = (t_Philo *)p_data;
	set_is_ready(philo, B_TRUE);
	wait_all_threads(philo->main_data);
	if (get_id(philo) % 2 != 0)
		milisecond_sleep(get_time_to_eat(philo->main_data));
	while (!get_must_stop(philo))
	{
		philo_action_chain(philo);
	}
	return (NULL);
}

void	philo_dinner_start(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		error_exit("Simulation Issue!");
	dinner_case_checks(data);
	data->stop_simulation = B_FALSE;
	data->start_time = get_time();
	i = 0;
	while (i < data->philo_num)
	{
		data->philo_arr[i].last_meal_time = data->start_time;
		thread_operation_handle(&data->philo_arr[i], &data->philo_arr[i].thread, time_to_feast, CREATE);
		++i;
	}
	observer(data);
	join_all_threads(data, time_to_feast);
}