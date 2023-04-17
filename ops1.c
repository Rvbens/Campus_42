/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:16:15 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/17 18:32:34 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sa(int *stk_a)
{
	(void) stk_a;
	ft_printf("sa\n");
}

void	ft_sb(int *stk_b)
{
	(void) stk_b;
	ft_printf("sb\n");
}

void	ft_ss(int *stk_a, int *stk_b)
{
	ft_sa(stk_a);
	ft_sb(stk_b);
}

void	ft_pa(int *stk_a, int *stk_b)
{
	(void) stk_a;
	(void) stk_b;
	ft_printf("pa\n");
}

void	ft_pb(int *stk_a, int *stk_b)
{
	(void) stk_a;
	(void) stk_b;
	ft_printf("pb\n");
}
