#include "../header/philosophers.h"

int	philo_pickup_fork(t_Philo *philo)
{
	if (!philo)
		return (B_FALSE);
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, LOCK);
	if (is_current_philo_dead(philo) == B_TRUE)
	{
		mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
		print_philo_action(philo, DEAD);
		philo->is_dead = B_TRUE;
		return (B_FALSE);
	}
	print_philo_action(philo, LEFT_FORK);
	mutex_operation_handle(philo->main_data, &philo->right_fork->fork, LOCK);
	if (is_current_philo_dead(philo) == B_TRUE)
	{
		mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
		mutex_operation_handle(philo->main_data, &philo->right_fork->fork, UNLOCK);
		print_philo_action(philo, DEAD);
		philo->is_dead = B_TRUE;
		return (B_FALSE);
	}
	print_philo_action(philo, RIGHT_FORK);
	return (B_TRUE);
}

int	philo_eat(t_Philo *philo)
{
	if (!philo)
		return (B_FALSE);
	philo->meals_count += 1;
	philo->last_meal_time = get_time();
	print_philo_action(philo, EAT);
	milisecond_sleep(philo->main_data->time_to_eat);
	if (philo->meals_count == philo->main_data->eat_limit)
		philo->is_full = B_TRUE;
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
	mutex_operation_handle(philo->main_data, &philo->right_fork->fork, UNLOCK);
	return (B_TRUE);
}

int	philo_sleep(t_Philo *philo)
{
	if (!philo)
		return (B_FALSE);
	print_philo_action(philo, SLEEP);
	milisecond_sleep(philo->main_data->time_to_sleep);
	return (B_TRUE);
}

int	philo_think(t_Philo *philo)
{
	if (!philo)
		return (B_FALSE);
	print_philo_action(philo, THINK);
	// usleep(1e3);
	return (B_TRUE);
}

int	philo_action_chain(t_Philo *philo)
{
	if (!philo)
		return (B_FALSE);
	if (philo->is_full == B_TRUE || philo->must_stop == B_TRUE)
		return (B_FALSE) ;
	if (is_current_philo_dead(philo) == B_TRUE)
		philo->is_dead = B_TRUE;
	if (philo->is_dead == B_TRUE)
	{
		print_philo_action(philo, DEAD);
		return (B_FALSE);
	}
	if (philo_pickup_fork(philo) == B_FALSE)
		return (B_FALSE);
	if (philo_eat(philo) == B_FALSE)
		return (B_FALSE);
	if (philo_sleep(philo) == B_FALSE)
		return (B_FALSE);
	if (philo_think(philo) == B_FALSE)
		return (B_FALSE);
	return (B_TRUE);
}