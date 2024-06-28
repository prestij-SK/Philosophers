#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <errno.h>

# include "data_and_consts.h"
# include "validation.h"
# include "utils.h"
# include "libft.h"

/*
	philosophers.c functions
*/
void	philo_start(char **argv, int argc);

/*
	data_init.c functions
*/
void	philo_data_init(t_PhiloData *data, char **argv, int argc);
void	philo_forks_data_init(t_PhiloData *data);
void	philo_data_delete(t_PhiloData *data);

/*
	thread_utils.c functions
*/
void	mutex_operation_handle(t_PhiloData *data, pthread_mutex_t *mutex, t_OpCode op_code);
void	mutex_error_handle(t_PhiloData *data, int status, t_OpCode op_code);
void	thread_operation_handle(t_PhiloData *data, pthread_t *thread, void *(*func)(void *), t_OpCode op_code);
void	thread_error_handle(t_PhiloData *data, int status, t_OpCode op_code);

#endif