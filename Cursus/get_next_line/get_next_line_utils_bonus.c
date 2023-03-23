/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:05:54 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/02 18:43:40 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

t_frag	*new_frag(t_buf	*buf)
{
	t_frag	*frag;
	int		i;

	frag = malloc(sizeof(t_frag));
	frag->str = malloc(buf->i - buf->lst_i);
	i = 0;
	while (buf->lst_i < buf->i)
		frag->str[i++] = buf->data[buf->lst_i++];
	frag->len = i;
	frag->next = 0;
	return (frag);
}

int	line_len(t_frag *start)
{
	int	len;

	len = 0;
	while (start)
	{
		len += start->len;
		start = start->next;
	}
	return (len);
}

void	free_frags(t_frag *start)
{
	t_frag	*tmp;

	while (start)
	{
		free(start->str);
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

char	*join_frags(t_frag *start)
{
	char	*str;
	t_frag	*next;
	int		i_frag;
	int		i_str;

	str = malloc(line_len(start) + 1);
	next = start;
	i_str = 0;
	while (next)
	{
		i_frag = 0;
		while (i_frag < next->len)
			str[i_str++] = next->str[i_frag++];
		next = next->next;
	}
	str[i_str] = 0;
	free_frags(start);
	return (str);
}
