#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

#include "data_and_consts.h"
#include "validation.h"
#include "utils.h"
#include "libft.h"

/*
	philosophers.c functions
*/
void	philo_start(char **argv, int argc);

/*
	data_init.c functions
*/
void	philo_data_init(t_PhiloData *data, char **argv, int argc);

#endif