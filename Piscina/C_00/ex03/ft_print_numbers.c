/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:31:03 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/20 18:41:14 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	n;

	n = '0';
	while (n <= '9')
	{
		write(1, &n, 1);
		n++;
	}
}
