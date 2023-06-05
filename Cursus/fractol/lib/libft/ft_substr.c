/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:13:12 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/16 13:04:05 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*ptr;
	t_size	sz;

	sz = ft_strlen(s);
	if (sz < start)
		sz = 0;
	else
		sz -= start;
	if (len < sz)
		sz = len;
	ptr = malloc(sz + 1);
	if (!ptr)
		return (0);
	if (sz)
		ft_strlcpy(ptr, &s[start], sz + 1);
	else
		*ptr = 0;
	return (ptr);
}
