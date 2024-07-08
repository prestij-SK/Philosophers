#include "../header/philosophers.h"

void	set_is_ready(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	philo->is_ready = set;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
}

void	set_is_full(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	philo->is_full = set;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
}

void	set_is_dead(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	philo->is_dead = set;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
}

void	set_must_stop(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->lock->fork, LOCK);
	philo->must_stop = set;
	mutex_operation_handle(philo->main_data, &philo->lock->fork, UNLOCK);
}