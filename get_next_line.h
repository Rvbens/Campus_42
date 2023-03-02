/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:05:52 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/02 18:44:57 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buf {
	char	data[BUFFER_SIZE];
	int		i;
	int		lst_i;
	int		len;
}	t_buf;

typedef struct s_frag {
	char			*str;
	int				len;
	struct s_frag	*next;
}	t_frag;

t_frag	*new_frag(t_buf	*buf);

char	*join_frags(t_frag *start);

char	*get_next_line(int fd);

#endif
