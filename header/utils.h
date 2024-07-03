#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

void	error_exit(char	*str);
void	success_exit(char *str);
size_t	get_time(void);
void	milisecond_sleep(size_t t_miliseconds);

#endif