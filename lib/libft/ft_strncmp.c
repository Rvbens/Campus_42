/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:09:49 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/30 13:44:22 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, t_size n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	int				i;

	if (!n)
		return (0);
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	i = 0;
	while (--n && s1[i] && s2[i])
	{
		if (u_s1[i] != u_s2[i])
			break ;
		i++;
	}
	return ((int)(u_s1[i] - u_s2[i]));
}
