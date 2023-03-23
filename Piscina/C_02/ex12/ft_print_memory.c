/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:25:57 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_dec_2_hex(unsigned int nb)
{
	nb %= 16;
	if (nb > 9)
		return (nb % 10 + 'a');
	else
		return (nb + '0');
}

void	ft_hex_byte(int c)
{
	ft_putchar(ft_dec_2_hex(c / 16));
	ft_putchar(ft_dec_2_hex(c));
}

void	ft_print_addr(void *addr)
{
	char	addr_arr[16];
	int		i;
	long	nb;

	i = 0;
	nb = (unsigned long) addr;
	while (i < 16)
	{
		addr_arr[15 - i] = ft_dec_2_hex(nb);
		i++;
		nb /= 16;
	}
	write(1, &addr_arr, 16);
	write(1, &": ", 2);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	c;
	int				i;

	c = 0;
	while (c < size)
	{
		ft_print_addr(addr);
		i = 0;
		while (i < 16)
		{
			write(1, &"00", 1);
			if (i % 2 == 1)
				ft_putchar(' ');
			addr++;
			i++;
		}
		ft_putchar(' ');
		ft_putchar('\n');
		c += 16;
	}
}
