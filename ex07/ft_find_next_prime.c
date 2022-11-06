/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:57:57 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/06 00:11:06 by rchaves-         ###   ########.fr       */
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
		return (min);
}

int	ft_is_prime_rec(int nb, int div, int max)
{
	if (div > max)
		return (1);
	if (nb % div == 0)
		return (0);
	else
		return (ft_is_prime_rec(nb, div + 2, max));
}

int	ft_is_prime(int nb)
{
	int	root;

	if (nb % 2 == 0 && nb != 2)
		return (0);
	if (nb > 1)
	{
		root = ft_binary_search(nb, 0, nb);
		return (ft_is_prime_rec(nb, 3, root));
	}
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	next_prime = nb + 1;
	while (!ft_is_prime(next_prime))
		next_prime++;
	return (next_prime);
}

/*#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(1));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(-1));
}*/
