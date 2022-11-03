/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:09:16 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/24 16:35:23 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nbr)
{
	int	c;

	if (c < 0)
		return (0);
	c = 1;
	while (nbr > 0)
		c *= nbr--;
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
	return (0);
}*/
