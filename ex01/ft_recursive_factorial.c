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

int	ft_recursive_factorial(int nbr)
{
	if (nbr < 0)
		return (0);
	else if (nbr == 1)
		return (1);
	else
		return (ft_recursive_factorial(nbr - 1) * nbr);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_factorial(3));
	return (0);
}*/
