/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 17:09:01 by rchaves-         ###   ########.fr       */
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

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_printf_lst(t_list *node)
{
	while (node)
	{
		ft_printf("Node: %d\n", *((int *) node->content));
		// ft_printf("Node dir : %d\n", node);
		// ft_printf("Node next : %d\n", node->next);
		node = node->next;
	}
}

int	main(int argn, char **argv)
{
	t_list	*stk_a;

	//atexit(ft_leaks);
	if (argn == 2)
	{	
		argv = ft_split(argv[1], 32);
		argn = 0;
		while (argv[argn])
			argn++;
	}
	else
	{
		argn--;
		argv++;
	}
	if (argn == 0)
		ft_error(0);
	stk_a = ft_arr_2_lst(argn, ft_check_input(argn, argv));
	ft_solver(&stk_a, argn);
	//ft_printf_lst(stk_a);
	ft_lstclear(&stk_a, &free);
	return (0);
}
