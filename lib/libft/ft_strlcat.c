/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:57:35 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/30 11:20:35 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcat(char *dst, const char *src, t_size dstsize)
{
	t_size	dst_l;
	t_size	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (dstsize == 0 || dstsize < dst_l + 1)
		return (src_l + dstsize);
	ft_strlcpy(dst + dst_l, src, dstsize - dst_l);
	return (dst_l + src_l);
}
