/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:07 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/30 12:58:58 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	t_size			i;
	unsigned char	c2;
	unsigned char	*s2;

	i = 0;
	c2 = (unsigned char) c;
	s2 = (unsigned char *) s;
	while (i < n)
	{
		if (s2[i] == c2)
			return ((void *) &s[i]);
		i++;
	}
	return (0);
}
