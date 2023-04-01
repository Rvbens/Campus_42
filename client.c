#define _GNU_SOURCE
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	sig;
	int	out;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sig = 1;
	if (*str == '-' || *str == '+')
		sig -= 2 * (*str++ == '-');
	out = 0;
	while (*str >= '0' && *str <= '9')
		out = out * 10 + (*str++ - '0');
	return (sig * out);
}

int	main(int argn, char **argv)
{
	if (argn==3)
		kill(ft_atoi(argv[1]), SIGUSR1);
	else
		write(1, &"Error\n", 7);
	return (0);
}