/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/19 21:32:03 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stk_a)
{
	t_list	*fst;
	t_list	*scd;

	fst = *stk_a;
	scd = fst->next;
	fst->next = scd->next;
	scd->next = fst;
	*stk_a = scd;
	ft_printf("sa\n");
}

void	ft_sb(t_list **stk_b)
{
	(void) stk_b;
	ft_printf("sb\n");
}

void	ft_ss(t_list **stk_a, t_list **stk_b)
{
	ft_sa(stk_a);
	ft_sb(stk_b);
}

void	ft_pa(t_list **stk_a, t_list **stk_b)
{
	(void) stk_a;
	(void) stk_b;
	ft_printf("pa\n");
}

void	ft_pb(t_list **stk_a, t_list **stk_b)
{
	t_list	*node;

	node = *stk_a;
	*stk_a = node->next;
	ft_lstadd_front(stk_b, node);
	ft_printf("pb\n");
}
