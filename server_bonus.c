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

void	sigusr_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static char	null_cnt;

	(void) context;
	if (signal == SIGUSR1)
		c |= 0x01;
	if (++i == 8)
	{
		if (c == 0)
			null_cnt++;
		if (null_cnt == 4)
		{	
			kill(info->si_pid, SIGUSR1);
			null_cnt = 0;
		}
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
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sigusr_handler;
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
