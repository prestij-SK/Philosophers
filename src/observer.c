#include "../header/philosophers.h"

static void stop_everyone(t_PhiloData *data)
{
	size_t philo_count;
	size_t i;

	philo_count = get_philo_num(data);
	i = 0;
	while (i < philo_count)
	{
		set_must_stop(&data->philo_arr[i], B_TRUE);
		++i;
	}
}

static int philosophers_full(t_PhiloData *data)
{
	size_t philo_count;
	size_t i;

	if (get_eat_limit(data) == UNDEFINED_VAL)
		return (B_FALSE);
	philo_count = get_philo_num(data);
	i = 0;
	while (i < philo_count)
	{
		if (get_is_full(&data->philo_arr[i]) == B_FALSE)
			return (B_FALSE);
		++i;
	}
	return (B_TRUE);
}

static int philosopher_died(t_PhiloData *data)
{
	size_t philo_count;
	size_t i;

	philo_count = get_philo_num(data);
	i = 0;
	while (i < philo_count)
	{
		mutex_operation_handle(data, &data->iterator_mtx, LOCK);
		if (get_time_to_die(data) < get_time() - get_last_meal_time(&data->philo_arr[i]))
		{
			print_philo_action(&data->philo_arr[i], DEAD);
			set_is_dead(&data->philo_arr[i], B_TRUE);
			mutex_operation_handle(data, &data->iterator_mtx, UNLOCK);
			return (B_TRUE);
		}
		mutex_operation_handle(data, &data->iterator_mtx, UNLOCK);
		++i;
	}
	return (B_FALSE);
}

void observer(t_PhiloData *data)
{
	if (!data)
		return;
	while (B_TRUE)
	{
		if (philosophers_full(data) == B_TRUE || philosopher_died(data) == B_TRUE)
		{
			stop_everyone(data);
			break;
		}
	}
}