/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:54:57 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/10 17:27:11 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	c;
	int	*arr;

	if (min >= max)
	{	
		*range = 0;
		return (0);
	}
	arr = malloc((max - min) * sizeof(int));
	if (!arr)
		return (-1);
	c = 0;
	while (c + min < max)
	{
		arr[c] = min + c;
		c++;
	}
	*range = arr;
	return (c);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	*p;
// 	int	c;
// 	int	i;

// 	p = 0;
// 	c = ft_ultimate_range(&p, 1, 4);
// 	i = 0;
// 	while (i < c)
// 	{
// 		printf("%d", p[i]);
// 		i++;
// 	}
// 	p = &i;
// 	printf("\n%p", p);
// 	c = ft_ultimate_range(&p, 2, 1);
// 	printf("\n%p", p);
// 	return (0);
// }
