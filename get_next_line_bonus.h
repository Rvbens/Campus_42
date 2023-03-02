/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:05:52 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/02 20:56:12 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX_FDS
#  define MAX_FDS 20
# endif

typedef struct s_buf {
	char	data[BUFFER_SIZE];
	int		i;
	int		lst_i;
	int		len;
}	t_buf;

typedef struct s_buf_dict {
	t_buf	buffers[MAX_FDS];
	int		keys[MAX_FDS];
	int		n_keys;
}	t_buf_dict;

typedef struct s_frag {
	char			*str;
	int				len;
	struct s_frag	*next;
}	t_frag;

t_frag	*new_frag(t_buf	*buf);

char	*join_frags(t_frag *start);

char	*get_next_line(int fd);

#endif
