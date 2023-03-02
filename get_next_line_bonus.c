/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:05:55 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/02 20:35:37 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

void	set_buffer(int fd, t_buf *buf)
{
	buf->len = read(fd, buf->data, BUFFER_SIZE);
	buf->i = 0;
	buf->lst_i = 0;
	if (buf->len < 0)
		buf->len = 0;
}

t_buf	*get_buffer(t_buf_dict *buf_dict, int fd)
{
	int	found;
	int	key;

	if (!buf_dict->n_keys)
		buf_dict->n_keys = 0;
	key = 0;
	found = 0;
	while (key < buf_dict->n_keys)
	{
		if (fd == buf_dict->keys[key])
		{
			found = 1;
			break ;
		}	
		key++;
	}
	if (!found)
	{
		buf_dict->keys[key] = fd;
		buf_dict->n_keys++;
	}
	return (&buf_dict->buffers[key]);
}

void	append_frag(t_buf *buf, t_frag **start, t_frag **frag)
{
	if (!*frag)
	{	
		*frag = new_frag(buf);
		*start = *frag;
	}
	else
	{
		(*frag)->next = new_frag(buf);
		*frag = (*frag)->next;
	}
}

char	*get_next_line(int fd)
{
	static t_buf_dict	buf_dict;
	t_buf				*buf;
	t_frag				*start;
	t_frag				*frag;

	frag = 0;
	buf = get_buffer(&buf_dict, fd);
	if (!buf->len || buf->i >= buf->len)
		set_buffer(fd, buf);
	if (!buf->len)
		return (0);
	while (buf->data[buf->i] != '\n' && buf->len)
	{
		if (buf->i == buf->len)
		{
			append_frag(buf, &start, &frag);
			set_buffer(fd, buf);
		}
		else
			buf->i++;
	}
	buf->i += (buf->data[buf->i] == '\n' && buf->len != buf->i);
	if (buf->len)
		append_frag(buf, &start, &frag);
	return (join_frags(start));
}
