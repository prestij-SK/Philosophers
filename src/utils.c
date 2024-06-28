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