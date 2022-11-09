/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:44:25 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/09 22:22:00 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != 0)
	{
		str++;
		c++;
	}
	return (c);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

t_stock_str	ft_set_stock(char *str)
{
	t_stock_str	stk;

	stk.size = ft_strlen(str);
	stk.str = str;
	stk.copy = malloc(stk.size + 1);
	ft_strncpy(stk.copy, str, stk.size + 1);
	return (stk);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			c;
	char		*end;
	t_stock_str	*arr;

	arr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!arr)
		return (NULL);
	c = 0;
	while (c < ac)
	{
		arr[c] = ft_set_stock(av[c]);
		c++;
	}
	end = malloc(1);
	end[0] = 0;
	arr[c] = ft_set_stock(end);
	return (arr);
}
