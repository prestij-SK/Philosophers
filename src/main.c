#include "../header/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error_exit("Arguments Count!");
	philo_start(argv, argc);
	return (EXIT_SUCCESS);
}