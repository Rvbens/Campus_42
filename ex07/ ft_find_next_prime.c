/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_find_next_prime.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:57:57 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/03 17:39:21 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_rec(int nb, int div)
{
	if (div == 1)
		return (1);
	if (nb % div == 0)
		return (0);
	else
		return (ft_is_prime_rec(nb, div - 1));
}

int	ft_is_prime(int nb)
{
	if (nb > 1)
		return (ft_is_prime_rec(nb, nb / 2));
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
	printf("%d", ft_is_prime(0));
	printf("%d", ft_is_prime(1));
	printf("%d", ft_is_prime(3));
	printf("%d", ft_is_prime(4));
	printf("%d", ft_is_prime(5));
	printf("%d", ft_is_prime(-1));
}*/
