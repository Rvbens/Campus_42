/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:39 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/04 11:25:39 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	sigusr_handler(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR1)
		c |= 0x01;
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

void	ft_set_sigactions(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	ft_set_sigactions();
	while (1)
		pause();
	return (0);
}
