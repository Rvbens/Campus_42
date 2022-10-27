/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:24:44 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_not_alpha(char c)
{
	int	out;

	out = (c < 'A' || c > 'z' || ((c > 'Z' && c < 'a')));
	return (out);
}

char	*ft_strcapitalize(char *str)
{
	int	c;
	int	cap;

	c = 0;
	cap = 1;
	while (str[c] != 0)
	{
		if (cap)
		{
			cap = 0;
			if (str[c] >= 'a' && str[c] <= 'z')
				str[c] -= 32;
		}
		else
		{
			if (str[c] >= 'A' && str[c] <= 'Z')
				str[c] += 32;
		}
		if (ft_is_not_alpha(str[c]) && (str[c] < '0' || str[c] > '9'))
			cap = 1;
		c++;
	}
	return (str);
}
