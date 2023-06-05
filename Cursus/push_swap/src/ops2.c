/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/28 11:12:58 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stk_a)
{
	t_list	*last;

	last = *stk_a;
	*stk_a = last->next;
	last->next = 0;
	ft_lstadd_back(stk_a, last);
	ft_printf("ra\n");
}

void	ft_rb(t_list **stk_b)
{
	t_list	*last;

	last = *stk_b;
	*stk_b = last->next;
	last->next = 0;
	ft_lstadd_back(stk_b, last);
	ft_printf("rb\n");
}

void	ft_rr(t_list **stk_a, t_list **stk_b)
{
	ft_ra(stk_a);
	ft_rb(stk_b);
}
