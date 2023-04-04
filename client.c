/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:27 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/04 11:25:27 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_atob(int pid, char *str)
{
	int		bt;
	char	c;

	while (*str)
	{
		bt = 0;
		c = *str;
		while (bt < 8)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bt++;
			c <<= 1;
			usleep(100);
		}
		str++;
	}
	pid += 1;
}

int	main(int argn, char **argv)
{
	if (argn == 3)
		ft_atob(ft_atoi(argv[1]), argv[2]);
	else
		write(1, &"Incorrect arguments: ./client PID message\n", 43);
	return (0);
}
