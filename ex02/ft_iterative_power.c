/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 06:56:42 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/06 00:25:18 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	out;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
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
	printf("%d\n", ft_iterative_power(1, -3));
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(2, 3));
	printf("%d\n", ft_iterative_power(2, 6));
	printf("%d\n", ft_iterative_power(3, 3));
	printf("%d\n", ft_iterative_power(-3, 3));
	printf("0^0: %d\n", ft_iterative_power(0, 0));
	printf("0^-1: %d\n", ft_iterative_power(0, -1));
	printf("0^1: %d\n", ft_iterative_power(0, 1));
	printf("%d\n", ft_iterative_power(-1, 6));
}*/
