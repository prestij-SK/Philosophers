#ifndef VALIDATION_H
# define VALIDATION_H

#include "philosophers.h"

// all times must be > 60
# define NOT_VALID 99
# define VALID 28
# define MAX_NUMBER_COUNT 19
# define MIN_TIME_LIMIT 60

int	is_philo_valid_args(char	**argv, int argc);
int	is_philo_valid_nums(t_Philosophers *data);
int	str_is_digits(char *str);

#endif