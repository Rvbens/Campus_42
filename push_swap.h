/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:26:43 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 14:48:16 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

void	ft_error(int *arr);

void	ft_printf_lst(t_list *node);

int		*ft_check_input(int len, char **argv);

void	ft_sa(t_list **stk_a);

void	ft_pa(t_list **stk_a, t_list **stk_b);

void	ft_pb(t_list **stk_a, t_list **stk_b);

void	ft_ra(t_list **stk_a);

void	ft_rb(t_list **stk_b);

void	ft_rr(t_list **stk_a, t_list **stk_b);

void	ft_rra(t_list **stk_a);

void	ft_solver(t_list **stk_a, int n);

void	ft_solver_small(t_list **stk_a, int n);

#endif