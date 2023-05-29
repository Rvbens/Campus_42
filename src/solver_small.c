/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:38:24 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/29 11:49:37 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_n(t_list *stk_a, int n)
{
	int	i;

	i = 0;
	while (stk_a)
	{
		if (*((int *) stk_a->content) == n)
			return (i);
		i++;
		stk_a = stk_a->next;
	}
	return (-1);
}

void	ft_solver_3(t_list **stk_a)
{
	if (*((int *)(*stk_a)->content) == 2)
		ft_ra(stk_a);
	else if (*((int *)(*stk_a)->next->content) == 2)
		ft_rra(stk_a);
	if (*((int *)(*stk_a)->content) > *((int *)(*stk_a)->next->content))
		ft_sa(stk_a);
}

void	ft_solver_4(t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = ft_find_n(*stk_a, 3);
	if (i == 1 || i == 2)
	{	
		ft_ra(stk_a);
		if (i == 2)
			ft_ra(stk_a);
	}
	else if (i == 3)
		ft_rra(stk_a);
	ft_pb(stk_a, stk_b);
	ft_solver_3(stk_a);
	ft_pa(stk_a, stk_b);
	ft_ra(stk_a);
}

void	ft_solver_5(t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = ft_find_n(*stk_a, 4);
	if (i == 1 || i == 2)
	{	
		ft_ra(stk_a);
		if (i == 2)
			ft_ra(stk_a);
	}
	else if (i == 3 || i == 4)
	{	
		ft_rra(stk_a);
		if (i == 3)
			ft_rra(stk_a);
	}
	ft_pb(stk_a, stk_b);
	ft_solver_4(stk_a, stk_b);
	ft_pa(stk_a, stk_b);
	ft_ra(stk_a);
}

void	ft_solver_small(t_list **stk_a, int n)
{
	t_list	**stk_b;

	if (n == 1)
		return ;
	stk_b = malloc(sizeof(t_list **));
	if (n <= 3)
		ft_solver_3(stk_a);
	else if (n == 4)
		ft_solver_4(stk_a, stk_b);
	else
		ft_solver_5(stk_a, stk_b);
	free(stk_b);
}
