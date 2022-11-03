/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 06:56:42 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/03 18:58:37 by rchaves-         ###   ########.fr       */
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
	printf("%d", ft_recursive_power(1, -3));
	printf("%d", ft_recursive_power(2, 3));
	printf("%d", ft_recursive_power(2, 0));
}*/
