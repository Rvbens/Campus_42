/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:57:11 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/29 14:29:48 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len--)
		*ptr++ = (unsigned char) c;
	return (b);
}
