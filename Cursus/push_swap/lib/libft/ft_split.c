/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:02 by rchaves-          #+#    #+#             */
/*   Updated: 2023/06/01 21:17:12 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(char const *s, char c)
{
	int	word_cnt;

	word_cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++word_cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (word_cnt);
}

char	**free_all(char **out, int word_i)
{
	while (word_i--)
		free(out[word_i]);
	free(out);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		len;
	int		i;

	out = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!out)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			out[i] = ft_substr(s - len, 0, len);
			if (!out[i++])
				return (free_all(out, i));
		}
		else
			++s;
	}
	out[i] = 0;
	return (out);
}
