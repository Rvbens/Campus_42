/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:57:57 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/03 09:05:03 by rchaves-         ###   ########.fr       */
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

/*#include <stdio.h>

int main(void)
{
	printf("0: %d\n", ft_is_prime(0));
	printf("1: %d\n", ft_is_prime(1));
	printf("2: %d\n", ft_is_prime(2));
	printf("3: %d\n", ft_is_prime(3));
	printf("4: %d\n", ft_is_prime(4));
	printf("5: %d\n", ft_is_prime(5));
	printf("-1: %d\n", ft_is_prime(-1));
	printf("97: %d\n", ft_is_prime(97));
}*/
