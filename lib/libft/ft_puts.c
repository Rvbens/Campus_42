/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:46:04 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/04 14:04:25 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchr(char c, int *cnt)
{	
	if (*cnt == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	(*cnt)++;
}

void	ft_putstr(char *str, int *cnt)
{
	if (!str)
		ft_putstr("(null)", cnt);
	while (str && *str)
		ft_putchr(*str++, cnt);
}

void	ft_recursion(long nbr, int base_n, char *base, int *cnt)
{
	if (nbr < 0)
	{
		ft_putchr('-', cnt);
		nbr *= -1;
	}
	if (nbr > base_n - 1)
		ft_recursion(nbr / base_n, base_n, base, cnt);
	ft_putchr(base[nbr % base_n], cnt);
}

void	ft_recursion_l(t_ulong nbr, t_uint base_n, char *base, int *cnt)
{
	if (nbr > base_n - 1)
		ft_recursion_l(nbr / base_n, base_n, base, cnt);
	ft_putchr(base[nbr % base_n], cnt);
}

void	ft_putnbr(t_ulong nbr, int mode, int *cnt)
{
	if (mode == 0)
	{
		ft_putstr("0x", cnt);
		ft_recursion_l(nbr, 16, "0123456789abcdef", cnt);
	}
	else if (mode == 1)
		ft_recursion(nbr, 10, "0123456789", cnt);
	else if (mode == 2)
		ft_recursion(nbr, 16, "0123456789abcdef", cnt);
	else if (mode == 3)
		ft_recursion(nbr, 16, "0123456789ABCDEF", cnt);
}
