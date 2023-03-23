/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:25:12 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	c;

	src_len = 0;
	while (src[src_len] != 0)
		src_len++;
	c = 0;
	if (size)
	{
		while (c < src_len && c < size)
		{
			dest[c] = src[c];
			c++;
		}
		if (size > src_len)
			dest[src_len] = 0;
		else
			dest[size - 1] = 0;
	}
	return (src_len);
}
