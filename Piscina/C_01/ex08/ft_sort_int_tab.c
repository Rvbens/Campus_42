/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:09:16 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:56 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	c;
	int	swp;

	c = 0;
	while (c < size - 1)
	{
		swp = 0;
		while (swp < size - 1 - c)
		{
			if (tab[swp] > tab[swp + 1])
				ft_swap(&tab[swp], &tab[swp + 1]);
			swp++;
		}
		c++;
	}
}
