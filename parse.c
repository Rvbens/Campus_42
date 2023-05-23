/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:17:05 by rchaves-          #+#    #+#             */
/*   Updated: 2023/05/23 12:20:44 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_error(int *arr)
{
	write(2, "Error\n", 6);
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
	int		j;

	i = 0;
	while (i < len)
	{
		str = argv[i++];
		j = 0;
		while (*str)
		{
			if (*str == '-' && str[1] == 0)
				return (1);
			if ((*str < '0' || *str > '9') && !(j == 0 && *str == '-'))
				return (1);
			str++;
			j++;
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
	int	*r;

	i = -1;
	r = malloc(len);
	ft_bzero(r, len);
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (i == j)
				continue ;
			if (arr[i] == arr[j])
				return (1);
			else if (arr[i] > arr[j])
				r[i]++;
		}
	}
	while (i--)
		arr[i] = r[i];
	free(r);
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
