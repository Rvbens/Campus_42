/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 06:56:42 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/03 07:24:39 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	out;

	if (power < 0)
		return (0);
	if (nb == 0)
		return (1);
	out = 1;
	while (power > 0)
	{
		out *= nb;
		power--;
	}
	return (out);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(2, 3));
}*/
