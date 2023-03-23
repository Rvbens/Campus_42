/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:25:40 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dec_2_hex(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
		ft_putchar(nb % 10 + 97);
	else
		ft_putchar(nb + 48);
}

void	ft_puthex(unsigned char nb)
{
	ft_putchar(92);
	ft_dec_2_hex(nb / 16);
	ft_dec_2_hex(nb % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		if (str[c] >= 32 && str[c] <= 126)
			ft_putchar(str[c]);
		else
			ft_puthex(str[c]);
		c++;
	}
}
