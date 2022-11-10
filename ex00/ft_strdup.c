/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:57:20 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/10 00:58:12 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{	
	int		c;
	char	*p;

	c = 0;
	while (src[c])
		c++;
	p = malloc(c + 1);
	if (!p)
		return (NULL);
	p[c + 1] = 0;
	while (c)
	{
		p[c] = src[c];
		c--;
	}
	return (p);
}
