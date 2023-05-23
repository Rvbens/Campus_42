/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:19 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:53 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stk_a)
{
	int	n1;
	int	n2;

	while (stk_a->next)
	{
		n1 = *((int *) stk_a->content);
		n2 = *((int *) stk_a->next->content);
		if (n1 + 1 != n2)
			return (0);
		stk_a = stk_a->next;
	}
	return (1);
}

void	ft_solver_big(t_list **stk_a, int n)
{
	t_list	**stk_b;
	int		bin;
	int		i;

	stk_b = malloc(sizeof(t_list **));
	*stk_b = 0;
	bin = 1;
	while (bin <= n - 1)
	{
		i = 0;
		while (i < n)
		{
			if (ft_is_sorted(*stk_a))
				break ;
			if (!(bin & *((int *)(*stk_a)->content)))
				ft_pb(stk_a, stk_b);
			else
				ft_ra(stk_a);
			i++;
		}
		while (*stk_b)
			ft_pa(stk_a, stk_b);
		bin <<= 1;
	}
	free(stk_b);
}

void	ft_solver(t_list **stk_a, int n)
{
	if (n <= 5)
		ft_solver_small(stk_a, n);
	else
		ft_solver_big(stk_a, n);
}
