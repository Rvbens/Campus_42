/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 14:24:56 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stk_a)
{
	t_list	*lst;
	t_list	*nxt_lst;

	nxt_lst = *stk_a;
	while (nxt_lst->next->next)
		nxt_lst = nxt_lst->next;
	lst = nxt_lst->next;
	lst->next = *stk_a;
	nxt_lst->next = 0;
	*stk_a = lst;
	ft_printf("rra\n");
}

void	ft_rrb(t_list **stk_b)
{
	(void) stk_b;
	ft_printf("rrb\n");
}

void	ft_rrs(t_list **stk_a, t_list **stk_b)
{
	ft_rra(stk_a);
	ft_rrb(stk_b);
}
