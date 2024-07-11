#include "../header/philosophers.h"

int	get_is_ready(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->is_ready;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

int	get_is_full(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->is_full;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

int	get_is_dead(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->is_dead;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

int	get_must_stop(t_Philo *philo)
{
	int	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->must_stop;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

size_t	get_last_meal_time(t_Philo *philo)
{
	size_t	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->last_meal_time;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

ssize_t	get_meals_count(t_Philo *philo)
{
	ssize_t	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->meals_count;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

size_t	get_id(t_Philo *philo)
{
	ssize_t	res;

	mutex_operation_handle(philo->main_data, &philo->philo_mtx, LOCK);
	res = philo->id;
	mutex_operation_handle(philo->main_data, &philo->philo_mtx, UNLOCK);
	return (res);
}

size_t	get_philo_num(t_PhiloData *data)
{
	size_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->philo_num;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

size_t	get_time_to_die(t_PhiloData *data)
{
	size_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->time_to_die;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

size_t	get_time_to_eat(t_PhiloData *data)
{
	size_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->time_to_eat;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

size_t	get_time_to_sleep(t_PhiloData *data)
{
	size_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->time_to_sleep;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

ssize_t	get_eat_limit(t_PhiloData *data)
{
	ssize_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->eat_limit;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

size_t	get_start_time(t_PhiloData *data)
{
	size_t	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->start_time;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}

int	get_stop_simulation(t_PhiloData *data)
{
	int	res;

	mutex_operation_handle(data, &data->getter_mtx, LOCK);
	res = data->stop_simulation;
	mutex_operation_handle(data, &data->getter_mtx, UNLOCK);
	return (res);
}