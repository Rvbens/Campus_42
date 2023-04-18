/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/17 19:35:24 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int *stk_a)
{
	(void) stk_a;
	ft_printf("ra\n");
}

void	ft_rb(int *stk_b)
{
	(void) stk_b;
	ft_printf("rb\n");
}

void	ft_rr(int *stk_a, int *stk_b)
{
	ft_ra(stk_a);
	ft_rb(stk_b);
}
