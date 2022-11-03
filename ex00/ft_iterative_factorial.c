/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:09:16 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/03 18:53:04 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nbr)
{
	int	c;

	if (nbr < 0)
		return (0);
	c = 1;
	while (nbr > 0)
		c *= nbr--;
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(3));
	return (0);
}*/
