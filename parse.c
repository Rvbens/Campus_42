/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:17:05 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/19 19:44:28 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *arr)
{
	ft_printf("Error\n");
	if (arr)
		free(arr);
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
	}
	return (arr);
}

// check for dups and return the arr with the
// numbers transformed to theirs ranks
int	ft_check_dups(int len, int *arr)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (i < len)
	{
		j = -1;
		r = 0;
		while (++j < len)
		{
			if (i == j)
				continue ;
			if (arr[i] == arr[j])
				return (1);
			else if (arr[i] > arr[j])
				r++;
		}
		arr[i] = r;
		i++;
	}
	return (0);
}

// Test: arg not int, arg > int, check duplicates
// return a pointer array or exit
// if there is an error. The array number are
// always positive and on increments of 1.
int	*ft_check_input(int len, char **argv)
{
	int		*arr;

	if (ft_check_num(len, argv))
		ft_error(0);
	arr = ft_check_long(len, argv);
	if (!arr)
		ft_error(0);
	if (ft_check_dups(len, arr))
		ft_error(arr);
	return (arr);
}
