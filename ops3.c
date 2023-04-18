/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/17 19:35:25 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(int *stk_a)
{
	(void) stk_a;
	ft_printf("rra\n");
}

void	ft_rrb(int *stk_b)
{
	(void) stk_b;
	ft_printf("rrb\n");
}

void	ft_rrs(int *stk_a, int *stk_b)
{
	ft_rra(stk_a);
	ft_rrb(stk_b);
}
