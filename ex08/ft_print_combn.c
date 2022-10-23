/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:31:03 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/22 23:29:00 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(char out[], int N)
{
	int		c;
	char	l;

	c = 0;
	while (c < N)
	{
		l = out[c] + 48;
		ft_putchar(l);
		c++;
	}
	if (out[0] < (10 - N))
	{
		write(1, &", ", 2);
	}
}

void	ft_rec_comb(int i, int c0, char out[], int N)
{
	while (c0 <= (10 - i))
	{
		out[N - i] = c0;
		if (i > 1)
		{
			ft_rec_comb(i - 1, c0 + 1, out, N);
		}
		else
		{
			ft_putnbr(out, N);
		}
		c0++;
	}
}

void	ft_print_combn(int n)
{
	char	out[9];

	ft_rec_comb(n, 0, out, n);
}
