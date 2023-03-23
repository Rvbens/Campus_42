/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:15 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/17 18:14:45 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	out[12];
	int		neg;
	int		i;

	neg = 0;
	out[11] = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		neg = 1;
		n *= -1;
	}
	i = 10;
	while (n > 9)
	{
		out[i--] = n % 10 + 48;
		n /= 10;
	}
	out[i] = n + 48;
	if (neg)
		out[--i] = '-';
	return (ft_strdup(out + i));
}
