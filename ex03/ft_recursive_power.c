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

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (power)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_power(3, 2));
}*/
