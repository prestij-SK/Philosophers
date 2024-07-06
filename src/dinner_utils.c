#include "../header/philosophers.h"

int	check_all_full(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		return (B_TRUE);
	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo_arr[i].is_full != B_TRUE)
			return (B_FALSE);
		++i;
	}
	return (B_TRUE);
}

int	is_current_philo_dead(t_Philo *philo)
{
	if (!philo)
		return (B_TRUE);
	if (philo->is_dead)
		return (B_TRUE);
	if (philo->main_data->time_to_die < (get_time() - philo->last_meal_time))
		return (B_TRUE);
	return (B_FALSE);
}

void	print_philo_action(t_Philo *philo, t_PhiloStatus op)
{
	size_t	id;
	size_t	time;

	if (!philo)
		return ;
	if (philo->must_stop == B_TRUE)
		return ;
	id = philo->id + 1;
	time = get_time();
	if (op == DEAD)
		printf("%zu %zu died\n", time - philo->timestamp, id);
	else if (op == LEFT_FORK)
		printf("%zu %zu has taken a fork\n", time - philo->timestamp, id);
	else if (op == RIGHT_FORK)
		printf("%zu %zu has taken a fork\n", time - philo->timestamp, id);
	else if (op == EAT)
		printf("%zu %zu is eating\n", time - philo->timestamp, id);
	else if (op == SLEEP)
		printf("%zu %zu is sleeping\n", time - philo->timestamp, id);
	else if (op == THINK)
		printf("%zu %zu is thinking\n", time - philo->timestamp, id);
	else
		printf("UNEXPECTED OPERATION!\n");
}

void	wait_all_threads(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		return ;
	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo_arr[i].is_ready == B_TRUE)
			++i;
	}	
}