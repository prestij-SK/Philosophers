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
void	print_philo_action(t_Philo *philo, t_PhiloStatus op);
int		philo_pickup_fork(t_Philo *philo);
int		philo_eat(t_Philo *philo);
int		philo_sleep(t_Philo *philo);
int		philo_think(t_Philo *philo);
void	wait_all_threads(t_PhiloData *data);
void	philo_action_chain(t_Philo *philo);

/*
	thread_utils.c functions
*/
void	mutex_operation_handle(t_PhiloData *data, pthread_mutex_t *mutex, t_PThreadOpCode op_code);
void	mutex_error_handle(t_PhiloData *data, int status, t_PThreadOpCode op_code);
void	thread_operation_handle(t_Philo *philo, pthread_t *thread, void *(*func)(void *), t_PThreadOpCode op_code);
void	thread_error_handle(t_PhiloData *data, int status, t_PThreadOpCode op_code);
void	join_all_threads(t_PhiloData *data, void *(*func)(void *));

/*
	observer.c functions
*/
void	observer(t_PhiloData *data);

/*
	getter.c functions
*/
int		get_is_ready(t_Philo *philo);
int		get_is_full(t_Philo *philo);
int		get_is_dead(t_Philo *philo);
int		get_must_stop(t_Philo *philo);
size_t	get_last_meal_time(t_Philo *philo);
ssize_t	get_meals_count(t_Philo *philo);
size_t	get_id(t_Philo *philo);
size_t	get_philo_num(t_PhiloData *data);
size_t	get_time_to_die(t_PhiloData *data);
size_t	get_time_to_eat(t_PhiloData *data);
size_t	get_time_to_sleep(t_PhiloData *data);
ssize_t	get_eat_limit(t_PhiloData *data);
size_t	get_start_time(t_PhiloData *data);
int		get_stop_simulation(t_PhiloData *data);

/*
	setter.c functions
*/
void	set_is_ready(t_Philo *philo, int set);
void	set_is_full(t_Philo *philo, int set);
void	set_is_dead(t_Philo *philo, int set);
void	set_must_stop(t_Philo *philo, int set);
void	update_meals_count(t_Philo *philo);
void	update_last_meal_time(t_Philo *philo);
void	set_stop_simulation(t_PhiloData *data, int set);

#endif