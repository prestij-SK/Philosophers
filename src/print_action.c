#include "../header/philosophers.h"

void	print_philo_action(t_Philo *philo, t_PhiloStatus op)
{
	size_t	id;
	size_t	time;

	mutex_operation_handle(philo->main_data, &philo->main_data->print_mtx, LOCK);
	if (get_must_stop(philo) != B_TRUE)
	{
		id = philo->id + 1;
		time = get_time() - get_start_time(philo->main_data);
		if (op == DEAD)
			printf("%zu %zu died\n", time, id);
		else if (op == LEFT_FORK)
			printf("%zu %zu has taken a fork\n", time, id);
		else if (op == RIGHT_FORK)
			printf("%zu %zu has taken a fork\n", time, id);
		else if (op == EAT)
			printf("%zu %zu is eating\n", time, id);
		else if (op == SLEEP)
			printf("%zu %zu is sleeping\n", time, id);
		else if (op == THINK)
			printf("%zu %zu is thinking\n", time, id);
		else
			printf("UNEXPECTED OPERATION!\n");
	}
	mutex_operation_handle(philo->main_data, &philo->main_data->print_mtx, UNLOCK);
}