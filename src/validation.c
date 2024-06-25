#include "../header/validation.h"
#include "../header/libft.h"

int	str_is_digits(char *str)
{
	int	i;

	if (!str)
		return (NOT_VALID);
	i = 0;
	while (ft_is_space(str[i]))
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (NOT_VALID);
		++i;
	}
	return (VALID);
}

int	is_philo_valid_args(char **argv, int argc)
{
	int i;

	if (!argv)
		return (NOT_VALID);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > MAX_NUMBER_COUNT)
			return (NOT_VALID);
		if (str_is_digits(argv[i]) == NOT_VALID)
			return (NOT_VALID);
		++i;
	}
	return (VALID);
}

int	is_philo_valid_nums(t_Philosophers *data)
{
	if (!data)
		return (NOT_VALID);
	if (data->time_to_die < MIN_TIME_LIMIT ||
		data->time_to_eat < MIN_TIME_LIMIT ||
		data->time_to_sleep < MIN_TIME_LIMIT)
	{
		return (NOT_VALID);
	}
	if (data->time_to_die <= 0 ||
		data->time_to_eat <= 0 ||
		data->time_to_sleep <= 0 ||
		data->philo_num <= 0)
	{
		return (NOT_VALID);
	}
	return (VALID);
}