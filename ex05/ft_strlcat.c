/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:40:52 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:40:56 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_l;
	unsigned int	src_l;
	unsigned int	i;

	dst_l = 0;
	while (dest[dst_l])
		dst_l++;
	src_l = 0;
	while (src[src_l])
		src_l++;
	if (size == 0 || size < dst_l + 1)
		return (src_l + size);
	i = 0;
	while (src[i] && i + dst_l + 1 < size)
	{
		dest[dst_l + i] = src[i];
		i++;
	}
	dest[dst_l + i] = 0;
	while (src[i])
		i++;
	return (dst_l + i);
}
