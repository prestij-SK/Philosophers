#include "../header/philosophers.h"

void	philo_data_delete(t_PhiloData *data)
{
	size_t	i;

	if (!data)
		return ;
	i = 0;
	if (data->fork_arr)
	{
		while (i < data->philo_num)
		{
			mutex_operation_handle(data, &data->fork_arr[i].fork, DESTROY);
			mutex_operation_handle(data, &data->philo_arr[i].philo_mtx, DESTROY);
			++i;
		}
	}
	mutex_operation_handle(data, &data->print_mtx, DESTROY);
	mutex_operation_handle(data, &data->getter_mtx, DESTROY);
	mutex_operation_handle(data, &data->setter_mtx, DESTROY);
	mutex_operation_handle(data, &data->iterator_mtx, DESTROY);
	free(data->philo_arr);
	data->philo_arr = NULL;
	free(data->fork_arr);
	data->fork_arr = NULL;
}

static int	philo_thread_data_init(t_PhiloData *data)
{
	if (!data)
		return (EXIT_FAILURE);
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
	philo_philosophers_data_init(data);
	return (EXIT_SUCCESS);
}

static int	philo_argument_data_init(t_PhiloData *data, char **argv, int argc)
{
	if (!data)
		return (EXIT_FAILURE);
	if (is_philo_valid_args(argv, argc) == NOT_VALID)
		return (EXIT_FAILURE);
	data->philo_num = ft_atosize_t(argv[1]);
	data->time_to_die = ft_atosize_t(argv[2]);
	data->time_to_eat = ft_atosize_t(argv[3]);
	data->time_to_sleep = ft_atosize_t(argv[4]);
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