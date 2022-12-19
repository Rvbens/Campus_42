/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:31:27 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/19 17:49:58 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef unsigned long	t_ulong;

typedef unsigned int	t_uint;

void	ft_putchr(char c, int *cnt);

void	ft_putstr(char *str, int *cnt);

void	ft_recursion(long nbr, int base_n, char *base, int *cnt);

void	ft_putnbr(t_ulong nbr, int mode, int *cnt);

int		ft_printf(char const *s, ...);

#endif
