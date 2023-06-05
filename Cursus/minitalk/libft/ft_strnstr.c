/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:21:48 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/17 19:13:05 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, t_size len)
{
	t_size	ndl_len;

	ndl_len = ft_strlen(needle);
	if (!ndl_len)
		return ((char *) haystack);
	if (haystack[0] && len >= ndl_len)
	{
		while (*haystack && (len-- - ndl_len + 1))
		{
			if (ft_strncmp(haystack, needle, ndl_len) == 0)
				return ((char *) haystack);
			haystack++;
		}
	}
	return (0);
}
