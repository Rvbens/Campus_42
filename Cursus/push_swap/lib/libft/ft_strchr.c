/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:32:45 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/30 11:56:08 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	c2;

	c2 = c;
	while (*s)
	{
		if (*s == c2)
			return ((char *) s);
		s++;
	}
	if (*s == c2)
		return ((char *) s);
	else
		return (0);
}