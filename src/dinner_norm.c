#include "../header/philosophers.h"

int	philo_pickup_fork(t_Philo *philo)
{
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, LOCK);
	print_philo_action(philo, LEFT_FORK);
	mutex_operation_handle(philo->main_data, &philo->right_fork->fork, LOCK);
	print_philo_action(philo, RIGHT_FORK);
	return (B_TRUE);
}

int	philo_eat(t_Philo *philo)
{
	update_meals_count(philo);
	print_philo_action(philo, EAT);
	milisecond_sleep(get_time_to_eat(philo->main_data));
	mutex_operation_handle(philo->main_data, &philo->left_fork->fork, UNLOCK);
	mutex_operation_handle(philo->main_data, &philo->right_fork->fork, UNLOCK);
	if (get_eat_limit(philo->main_data) == get_meals_count(philo))
		set_is_full(philo, B_TRUE);
	update_last_meal_time(philo);
	return (B_TRUE);
}

int	philo_sleep(t_Philo *philo)
{
	print_philo_action(philo, SLEEP);
	milisecond_sleep(get_time_to_sleep(philo->main_data));
	return (B_TRUE);
}

int	philo_think(t_Philo *philo)
{
	print_philo_action(philo, THINK);
	// usleep(1e3);
	return (B_TRUE);
}

void	philo_action_chain(t_Philo *philo)
{
	philo_pickup_fork(philo);
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);
}