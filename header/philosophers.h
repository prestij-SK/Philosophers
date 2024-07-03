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
void	philo_philosophers_data_init(t_PhiloData *data);
void	philo_data_delete(t_PhiloData *data);

/*
	dinner.c functions
*/
void	philo_dinner_start(t_PhiloData *data);
int		check_all_full(t_PhiloData *data);
int		is_current_philo_dead(t_Philo *philo);

/*
	thread_utils.c functions
*/
void	mutex_operation_handle(t_PhiloData *data, pthread_mutex_t *mutex, t_PThreadOpCode op_code);
void	mutex_error_handle(t_PhiloData *data, int status, t_PThreadOpCode op_code);
int		thread_operation_handle(pthread_t *thread, void *(*func)(void *), void *p_data, t_PThreadOpCode op_code);
void	thread_error_handle(t_PhiloData *data, int status, t_PThreadOpCode op_code);
void	join_all_threads(t_PhiloData *data, void *(*func)(void *));

#endif