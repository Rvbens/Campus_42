/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:21:03 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	out;

	out = 1;
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			out = 0;
		str++;
	}
	return (out);
}
