/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:26:43 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/19 21:37:25 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

int		*ft_check_input(int len, char **argv);

void	ft_sa(t_list **stk_a);

void	ft_pb(t_list **stk_a, t_list **stk_b);

void	ft_ra(t_list **stk_a);

void	ft_solver(t_list **stk_a, int n, int n_bits);

#endif