/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/22 19:12:47 by rchaves-         ###   ########.fr       */
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
	(void) stk_b;
	ft_printf("rb\n");
}

void	ft_rr(t_list **stk_a, t_list **stk_b)
{
	ft_ra(stk_a);
	ft_rb(stk_b);
}
