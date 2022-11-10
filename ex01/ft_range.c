/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:54:57 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/10 17:39:40 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	c;
	int	*arr;

	if (min >= max)
	{	
		arr = 0;
		return (arr);
	}
	arr = malloc((max - min) * sizeof(int));
	c = 0;
	while (c + min < max)
	{
		arr[c] = min + c;
		c++;
	}
	return (arr);
}
/*#include <stdio.h>
int	main(void)
{
	int	*p;
	int	min = 1;
	int	max = 4;
	int i;

	p = ft_range(min, max);
	i = 0;
	while (i < max - min)
	{
		printf("%d", p[i]);
		i++;
	}
	return (0);
}*/
