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

static void	*time_to_feast(void *p_data)
{
	t_Philo	*philo;

	philo = (t_Philo *)p_data;
	if (philo->id % 2 == 0)
		milisecond_sleep(philo->main_data->time_to_eat);
	while (1)
	{
		if (is_current_philo_dead(philo) == B_TRUE)
		{
			// print
			philo->is_dead = B_TRUE;
			// printf("Philo: [%zu]   MAN I'M DEAD\n", philo->id + 1);
			// break ;
		}
		if (philo->is_dead = B_TRUE)
		{
			printf("Philo: [%zu]   MAN I'M DEAD\n", philo->id + 1);
			break ;
		}
		// pthread_mutex_lock(&philo->left_fork->fork);
		// pthread_mutex_unlock(&philo->left_fork->fork);
		// pthread_mutex_lock(&philo->right_fork->fork);
		// pthread_mutex_unlock(&philo->right_fork->fork);
	}
	return (NULL);
}

static void	dinner_simulation(t_PhiloData *data)
{
	size_t	i;
	int		status;

	if (!data)
		error_exit("Simulation Issue!");
	i = 0;
	while (i < data->philo_num)
	{
		data->philo_arr[i].last_meal_time = get_time();
		status = thread_operation_handle(&data->philo_arr[i].thread, time_to_feast, &data->philo_arr[i], CREATE);
		thread_error_handle(data, status, CREATE);
		++i;
	}
}

static void	observer(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		error_exit("Simulation Issue!");
	if (check_all_full(data) == B_TRUE)
	{
		philo_data_delete(data);
		success_exit("Simulation Ended!");
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo_arr[i].is_dead == B_TRUE)
		{
			philo_data_delete(data);
			success_exit("Simulation Ended!");
		}
		++i;
	}
}

void	philo_dinner_start(t_PhiloData *data)
{
	if (!data)
		error_exit("Simulation Issue!");
	dinner_case_checks(data);
	while (B_TRUE)
	{
		observer(data);
		printf("Monitor\n");
		usleep(1000000); // To wait a little before continueing after checking
		dinner_simulation(data);
	}
	join_all_threads(data, NULL);
	philo_data_delete(data);
	success_exit("Simulation Ended!");
}