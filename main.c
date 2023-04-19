/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/19 19:46:05 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// convert the number array to a list.
t_list	*ft_arr_2_lst(int len, int *arr)
{
	t_list	*start;
	t_list	*node;
	int		*cnt;
	int		i;

	i = 0;
	cnt = malloc(sizeof(int));
	*cnt = arr[i];
	start = ft_lstnew(cnt);
	node = start;
	while (++i < len)
	{
		cnt = malloc(sizeof(int));
		*cnt = arr[i];
		node->next = ft_lstnew(cnt);
		node = node->next;
	}
	free(arr);
	return (start);
}

// count the number of bits to represent
// the biggest number
int	ft_n_bits(t_list *stk)
{
	int	b_max;
	int	b_n;
	int	num;
	int	b;

	b_max = 0;
	while (stk)
	{
		num = *((int *) stk->content);
		b = 1;
		b_n = 0;
		while (b_n < 31)
		{
			if (num & b && b_n > b_max)
			{	
				b_max = b_n;
			}
			b <<= 1;
			b_n++;
		}
		stk = stk->next;
	}
	return (b_max + 1);
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argn, char **argv)
{
	t_list	*stk_a;
	int		n_bits;

	atexit(ft_leaks);
	if (argn == 1)
		return (0);
	argn--;
	argv++;
	stk_a = ft_arr_2_lst(argn, ft_check_input(argn, argv));
	n_bits = ft_n_bits(stk_a);
	ft_printf("N bits: %d\n", n_bits);
	//ft_solver(stk_a, argn, n_bits);
	t_list	*node;
	node = stk_a;
	while (node)
	{
		ft_printf("Node: %d\n", *((int *) node->content));
		node = node->next;
	}
	ft_lstclear(&stk_a, &free);
	return (0);
}
