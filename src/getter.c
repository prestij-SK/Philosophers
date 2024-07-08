#include "../header/philosophers.h"

int	get_is_ready(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	res = philo->is_ready;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
	return (res);
}

int	get_is_full(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	res = philo->is_full;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
	return (res);
}

int	get_is_dead(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	res = philo->is_dead;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
	return (res);
}

int	get_must_stop(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	res = philo->must_stop;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
	return (res);
}