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

void	ft_itoaw(int n)
{
	char	d;

	if (n < 0)
	{
		write(1, &"-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_itoaw(n / 10);
	d = n % 10 + '0';
	write(1, &d, 1);
}

void	sigusr_handler(int signal)
{
	static int	i;
	static char	c;

	if (!i)
	{
		i = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c |= 0x01;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
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
	ft_itoaw(getpid());
	write(1, &"\n", 1);
	ft_set_sigactions();
	while (1)
		pause();
	return (0);
}
