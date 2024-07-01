#include "../header/philosophers.h"

void	mutex_operation_handle(t_PhiloData *data, pthread_mutex_t *mutex, t_OpCode op_code)
{
	int	status;

	if (!mutex || !data)
	{
		philo_data_delete(data);
		error_exit("Mutex Operation!");
	}
	status = EXIT_SUCCESS;
	if (op_code == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (op_code == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (op_code == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (op_code == DESTROY)
		status = pthread_mutex_destroy(mutex);
	else
		status = EXIT_FAILURE;
	mutex_error_handle(data, status, op_code);
}

void	mutex_error_handle(t_PhiloData *data, int status, t_OpCode op_code)
{
	if (!data)
		error_exit("Mutex Operation!");
	if (status != EXIT_SUCCESS)
		philo_data_delete(data);
	else
		return ;
	if (status == EXIT_FAILURE)
		error_exit("Mutex Operation!");
	else if (status == EINVAL && (op_code == LOCK || op_code == UNLOCK))
		error_exit("The value specified by mutex is invalid.");
	else if (status == EINVAL && op_code == INIT)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (status == EBUSY)
		error_exit("Mutex is locked.");
	else
		error_exit("Other Mutex Issue!");
}

// There should be t_PhiloData *data in parameters of this function, but Norminette won't let me do it.
// So, it is what it is.
int	thread_operation_handle(pthread_t *thread, void *(*func)(void *), void *p_data, t_OpCode op_code)
{
	int	status;

	if (!thread || !p_data || !func)
		return (EXIT_FAILURE);
	status = EXIT_SUCCESS;
	if (op_code == CREATE)
		status = pthread_create(thread, NULL, func, p_data);
	else if (op_code == JOIN)
		status = pthread_join(*thread, NULL);
	else if (op_code == DETACH)
		status = pthread_detach(*thread);
	else
		status = EXIT_FAILURE;
	return (status);
}

void	thread_error_handle(t_PhiloData *data, int status, t_OpCode op_code)
{
	if (!data)
		error_exit("Thread Operation!");
	if (status != EXIT_SUCCESS)
		philo_data_delete(data);
	else
		return ;
	if (status == EXIT_FAILURE)
		error_exit("Thread Operation!");
	else if (status == EAGAIN)
		error_exit("No resources to create another thread.");
	else if (status == EPERM)
		error_exit("The caller does not have appropriate permission");
	else if (status == EINVAL && op_code == CREATE)
		error_exit("The value specified by attr is invalid.");
	else if (status == EINVAL && (op_code == JOIN || op_code == DETACH))
		error_exit("The value specified by thread is not joinable.");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that specified by the given thread ID, thread.");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or the value of thread specifies the calling thread.");
	else
		error_exit("Other Thread Issue!");
}