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
	if (nb > 9)
		ft_putchar(nb % 10 + 'a');
	else
		ft_putchar(nb + '0');
}

void	ft_puthex(int nb)
{
	write(1, &"\\", 1);
	ft_dec_2_hex(nb / 16);
	ft_dec_2_hex(nb % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != 0)
	{
		if (str[c] >= ' ' && str[c] <= '~')
			ft_putchar(str[c]);
		else
			ft_puthex(str[c]);
		c++;
	}
}
