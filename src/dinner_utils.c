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