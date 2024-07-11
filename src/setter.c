#include "../header/philosophers.h"

void	set_is_ready(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->is_ready = set;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	set_is_full(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->is_full = set;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	set_is_dead(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->is_dead = set;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	set_must_stop(t_Philo *philo, int set)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->must_stop = set;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	update_meals_count(t_Philo *philo)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->meals_count += 1;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	update_last_meal_time(t_Philo *philo)
{
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	philo->last_meal_time = get_time();
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
}

void	set_stop_simulation(t_PhiloData *data, int set)
{
	mutex_operation_handle(data, &data->setter_mtx, LOCK);
	data->stop_simulation = set;
	mutex_operation_handle(data, &data->setter_mtx, UNLOCK);
}