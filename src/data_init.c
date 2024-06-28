#include "../header/philosophers.h"

void	philo_data_delete(t_PhiloData *data)
{
	if (!data)
		return ;
	data->philo_num = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->eat_limit = UNDEFINED_VAL;
	free(data->philo_arr);
	data->philo_arr = NULL;
	free(data->fork_arr);
	data->fork_arr = NULL;
	// data->simulate_start = B_FALSE;
	// data->simulate_end = B_TRUE;
}

static int	philo_thread_data_init(t_PhiloData *data)
{
	if (!data)
		return (EXIT_FAILURE);
	data->simulate_start = B_TRUE;
	data->simulate_end = B_FALSE;
	data->fork_arr = NULL;
	data->philo_arr = NULL;
	data->philo_arr = (t_Philo *)malloc(sizeof(t_Philo) * (data->philo_num));
	data->fork_arr = (t_Fork *)malloc(sizeof(t_Fork) * (data->philo_num));
	if (!data->fork_arr || !data->philo_arr)
	{
		philo_data_delete(data);
		return (EXIT_FAILURE);
	}
	philo_forks_data_init(data);
	return (EXIT_SUCCESS);
}

static int	philo_argument_data_init(t_PhiloData *data, char **argv, int argc)
{
	if (!data)
		return (EXIT_FAILURE);
	if (is_philo_valid_args(argv, argc) == NOT_VALID)
		return (EXIT_FAILURE);
	data->philo_num = ft_atosize_t(argv[1]);
	data->time_to_die = ft_atosize_t(argv[2]) * MILLISECOND_VALUE;
	data->time_to_eat = ft_atosize_t(argv[3]) * MILLISECOND_VALUE;
	data->time_to_sleep = ft_atosize_t(argv[4]) * MILLISECOND_VALUE;
	if (argc == 6)
		data->eat_limit = ft_atosize_t(argv[5]);
	else
		data->eat_limit = UNDEFINED_VAL;
	if (is_philo_valid_nums(data) == NOT_VALID)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	philo_data_init(t_PhiloData *data, char **argv, int argc)
{
	if (!data)
		error_exit("Not Valid Arguments!");
	if (philo_argument_data_init(data, argv, argc) == EXIT_FAILURE)
		error_exit("Not Valid Arguments!");
	if (philo_thread_data_init(data) == EXIT_FAILURE)
		error_exit("Initializing Issue!");
}