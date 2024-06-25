#include "../header/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Arguments Count!\n");
		return (EXIT_FAILURE);
	}
	return (philo_start(argv, argc));
}