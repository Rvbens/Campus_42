/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:06:32 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/19 20:00:07 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	format_calls(char const *s, va_list args_p, int *cnt)
{
	if (*s == 'c')
		ft_putchr(va_arg(args_p, int), cnt);
	else if (*s == 's')
		ft_putstr(va_arg(args_p, char *), cnt);
	else if (*s == 'p')
		ft_putnbr(va_arg(args_p, t_ulong), 0, cnt);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args_p, int), 1, cnt);
	else if (*s == 'u')
		ft_putnbr(va_arg(args_p, t_uint), 1, cnt);
	else if (*s == 'x')
		ft_putnbr(va_arg(args_p, t_uint), 2, cnt);
	else if (*s == 'X')
		ft_putnbr(va_arg(args_p, t_uint), 3, cnt);
	else if (*s == '%')
		ft_putchr('%', cnt);
}

int	ft_printf(char const *s, ...)
{
	int		cnt;
	va_list	args_p;

	va_start(args_p, s);
	cnt = 0;
	while (*s && cnt != -1)
	{
		if (*s == '%')
			format_calls(++s, args_p, &cnt);
		else
			ft_putchr(*s, &cnt);
		s++;
	}
	va_end(args_p);
	return (cnt);
}
