#ifndef VALIDATION_H
# define VALIDATION_H

#include "philosophers.h"

# define NOT_VALID 99
# define VALID 28
# define MAX_NUMBER_COUNT 19
# define MILLISECOND_VALUE 1e3
# define MIN_TIME_LIMIT 6e4

int	is_philo_valid_args(char	**argv, int argc);
int	is_philo_valid_nums(t_Philosophers *data);
int	str_is_digits(char *str);

#endif