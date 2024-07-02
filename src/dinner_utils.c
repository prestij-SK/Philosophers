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