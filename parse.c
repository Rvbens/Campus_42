/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:17:05 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/18 21:21:22 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

// returns 1 if some parameters has a 
// character that is not a number.
int	ft_check_num(int len, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	while (i < len)
	{
		str = argv[i++];
		while (*str)
		{
			if ((*str < '0' || *str > '9') && *str != '-')
				return (1);
			str++;
		}
	}
	return (0);
}

int	*ft_check_long(int len, char **argv)
{
	int		*arr;
	long	n;
	int		i;

	i = 0;
	arr = malloc(len * sizeof(int));
	while (i < len)
	{
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			free(arr);
			return (0);
		}
		arr[i++] = (int) n;
		//ft_printf("save: %d\n", arr[i-1]);
	}
	return (arr);
}

int	ft_check_dups(int len, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

// arg not int, arg > int, check duplicates
// return a pointer to the list or NULL
// if there is an error
t_list	*ft_check_input(int len, char **argv)
{
	t_list	*start;
	t_list	*node;
	int		*cnt;
	int		*arr;
	int		i;

	if (ft_check_num(len, argv))
		ft_error();
	arr = ft_check_long(len, argv);
	if (!arr)
		ft_error();
	if (ft_check_dups(len, arr))
	{
		free(arr);
		ft_error();
	}
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
