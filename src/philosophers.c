#include "../header/philosophers.h"
#include "../header/validation.h"
#include "../header/libft.h"

int	philo_data_init(t_Philosophers *data, char **argv, int argc)
{
	if (!data)
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
	{
		printf("Error: Not Valid Arguments!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	philo_start(char **argv, int argc)
{
	t_Philosophers	data;

	if (!argv)
		return (EXIT_FAILURE);
	if (is_philo_valid_args(argv, argc) == NOT_VALID)
	{
		printf("Error: Not Valid Arguments!\n");
		return (EXIT_FAILURE);
	}
	if (philo_data_init(&data, argv, argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// printf("\n%zu %zu %zu %zu %zu\n", data.philo_num, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.eat_limit);
	return (EXIT_SUCCESS);
}