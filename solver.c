/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:19 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/19 21:37:47 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solver(t_list **stk_a, int n, int max)
{
	t_list	**stk_b;
	int		bin;
	int		i;

	stk_b = 0;
	bin = 1;
	while (bin < max)
	{
		i = 0;
		while (i < n)
		{
			if (!(bin & *((int *)(*stk_a)->content)))
				ft_pb(stk_a, stk_b);
			else
				ft_ra(stk_a);
			i++;
		}
		// push back to a
		bin <<= 1;
	}
	(void) stk_a;
}
