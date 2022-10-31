/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:40:52 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/27 22:40:56 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (*src && j < nb)
	{
		dest[i + j] = *src;
		src++;
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}
