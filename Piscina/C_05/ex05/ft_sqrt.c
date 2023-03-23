/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:03:53 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/06 00:09:58 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_binary_search(long nb, int min, int max)
{
	int	half;

	if (min * min == nb)
		return (min);
	else if (max * max == nb)
		return (max);
	if (max - min > 1)
	{
		half = (max + min) / 2;
		if (half > 46340)
			half = 46340;
		if (half * half > nb)
			return (ft_binary_search(nb, min, half));
		else
			return (ft_binary_search(nb, half, max));
	}
	else
		return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_binary_search(nb, 0, nb));
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(-4));
	printf("%d\n", ft_sqrt(12345 * 12345));
	printf("%d\n", ft_sqrt(-46339*46339));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147483647)); //2147395600
}*/
