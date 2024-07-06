#include "../header/utils.h"

void	error_exit(char	*str)
{
	if (!str)
		exit(EXIT_FAILURE);
	printf("Error: %s\n", str);
	exit(EXIT_FAILURE);
}

void	success_exit(char *str)
{
	if (!str)
		exit(EXIT_SUCCESS);
	printf("Success: %s\n", str);
	exit(EXIT_SUCCESS);
}

size_t	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void	milisecond_sleep(size_t t_miliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < t_miliseconds)
		usleep(500);
}