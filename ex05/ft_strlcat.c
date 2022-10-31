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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (*src && j < size - i - 1)
	{
		dest[i + j] = *src;
		src++;
		j++;
	}
	dest[i + j] = 0;
	while (*src)
	{
		src++;
		j++;
	}
	return (i + j);
}
