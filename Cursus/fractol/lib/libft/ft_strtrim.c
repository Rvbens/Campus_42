/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:49:59 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/17 13:33:17 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	t_size	set_len;
	t_size	s1_len;
	t_size	i;

	set_len = ft_strlen(set);
	while (s1)
	{
		i = 0;
		while (set[i] && ft_memcmp(s1, &set[i], 1))
			i++;
		if (i == set_len)
			break ;
		s1++;
	}
	s1_len = ft_strlen(s1);
	while (s1_len)
	{
		i = 0;
		while (set[i] && ft_memcmp(&s1[s1_len - 1], &set[i], 1))
			i++;
		if (i == set_len)
			break ;
		s1_len--;
	}
	return (ft_substr(s1, 0, s1_len));
}
