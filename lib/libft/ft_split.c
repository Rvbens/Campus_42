/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:02 by rchaves-          #+#    #+#             */
/*   Updated: 2022/12/17 19:29:21 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	is_eow(char const *s, char c)
{
	return (*s != c && (s[1] == c || s[1] == 0));
}

char	is_sow(char const *s, char c, char i)
{
	if (!i)
		return (*s != c);
	else
		return (*s != c && (s[-1] == c));
}

char	count_words(char const *s, char c)
{
	char	word_cnt;

	word_cnt = 0;
	while (*s)
	{
		if (is_eow(s++, c))
			word_cnt++;
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
	char	word_cnt;
	int		word_i;
	int		str_i;
	int		i;

	word_cnt = count_words(s, c);
	out = malloc(sizeof(char *) * (word_cnt + 1));
	if (!out)
		return (0);
	i = -1;
	word_i = 0;
	while (s[++i])
	{
		if (is_sow(&s[i], c, i))
			str_i = i;
		if (is_eow(&s[i], c))
		{
			out[word_i] = ft_substr(s, str_i, i - str_i + 1);
			if (!out[word_i++])
				return (free_all(out, word_i));
		}
	}
	out[word_i] = 0;
	return (out);
}
