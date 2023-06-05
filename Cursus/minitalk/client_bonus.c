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
#include <stdlib.h>
#include "libft.h"

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
	bt = 32;
	while (bt-- > 0)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

void	sigusr_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Confirmation received from server.\n");
		exit(0);
	}
}

void	ft_set_cl_sigactions(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
}

int	main(int argn, char **argv)
{
	ft_set_cl_sigactions();
	if (argn == 3)
	{
		ft_atob(ft_atoi(argv[1]), argv[2]);
		sleep(1);
		ft_printf("Confirmation not received from server.\n");
	}
	else
		write(1, &"Incorrect arguments: ./client PID message\n", 43);
	return (0);
}
