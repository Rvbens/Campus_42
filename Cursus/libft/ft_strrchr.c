/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:58:19 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/30 12:07:46 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*out;

	c2 = c;
	out = 0;
	while (*s)
	{
		if (*s == c2)
			out = (char *) s;
		s++;
	}
	if (*s == c2)
		out = (char *) s;
	return (out);
}
