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
}

int	main(int argn, char **argv)
{
	if (argn == 3)
		ft_atob(ft_atoi(argv[1]), argv[2]);
	else
		write(1, &"Incorrect arguments: ./client PID message\n", 43);
	return (0);
}
