#ifndef VALIDATION_H
# define VALIDATION_H

#include "data_and_consts.h"
#include "libft.h"

int	is_philo_valid_args(char	**argv, int argc);
int	is_philo_valid_nums(t_PhiloData *data);
int	str_is_digits(char *str);

#endif