/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by rchaves-          #+#    #+#             */
/*   Updated: 2023/06/04 16:36:32 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_printf_lst(t_list *node)
{
	while (node)
	{
		ft_printf("Node: %d\n", *((int *) node->content));
		node = node->next;
	}
}

void	ft_freeall(int quote_bool, int argn, char **argv, t_list *stk_a)
{
	if (quote_bool)
	{	
		while (argn--)
			free(argv[argn]);
		free(argv);
	}
	ft_lstclear(&stk_a, &free);
}

// void	ft_leaks(void)
// {
// 	system("leaks -q push_swap");
// }
//atexit(ft_leaks);

int	main(int argn, char **argv)
{
	t_list	*stk_a;
	int		quote_bool;

	quote_bool = 0;
	if (argn == 1)
		return (0);
	else if (argn == 2)
	{	
		quote_bool = 1;
		argv = ft_split(argv[1], ' ');
		argn = 0;
		while (argv[argn])
			argn++;
	}
	else
	{
		argn--;
		argv++;
	}
	stk_a = ft_arr_2_lst(argn, ft_check_input(argn, argv));
	ft_solver(&stk_a, argn);
	ft_freeall(quote_bool, argn, argv, stk_a);
	return (0);
}
