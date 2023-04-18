/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/18 18:18:12 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_n_bits(t_list *stk)
{
	int	b_max;
	int	b_n;
	int	num;
	int	b;

	b_max = 0;
	while (stk)
	{
		num = (int) stk->content;
		b = 1;
		b_n = 0;
		while (b_n < 31)
		{
			if (num & b && b_n > b_max)
				b_max = b_n;
			b <<= 1;
			b_n++;
		}
		stk = stk->next;
	}
	return (b_max + 1);
}

void	ft_leaks(void) //borrar
{
	system("leaks -q push_swap");
}

int	main(int argn, char **argv)
{
	t_list	*stk_a;
	int		n_bits;

	atexit(ft_leaks); //borrar
	if (argn == 1)
		return (0);
	argn--;
	stk_a = ft_check_input(argn, argv);
	n_bits = ft_n_bits(stk_a);
	ft_solver(stk_a, argn, n_bits);
	return (0);
}
