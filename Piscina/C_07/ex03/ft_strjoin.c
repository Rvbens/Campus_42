/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:52:16 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/10 19:45:07 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_strcpy_adv(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
			dest[i] = src[i];
			i++;
	}
	return (i);
}

int	ft_total_size(int size, char **strs, char *sep)
{
	int		out_l;
	int		not_null;
	int		str_i;

	not_null = 0;
	str_i = 0;
	out_l = 1;
	while (str_i < size)
	{
		if (strs[str_i])
		{
			out_l += ft_strlen(strs[str_i]);
			not_null++;
		}
		str_i++;
	}
	out_l = ft_strlen(sep) * (not_null - 1) * (size != 0);
	return (out_l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		str_i;
	int		out_i;

	out = malloc(ft_total_size(size, strs, sep));
	str_i = 0;
	out_i = 0;
	while (str_i < size)
	{	
		if (strs[str_i])
		{
			out_i += ft_strcpy_adv(&out[out_i], strs[str_i]);
			if (str_i < size - 1)
				out_i += ft_strcpy_adv(&out[out_i], sep);
		}
		str_i++;
	}
	out[out_i] = 0;
	return (out);
}
/*#include <stdio.h>
int	main(void)
{
	char *out;
	char *list[3];
	char *sep  = " -";
	char *str1 = "Hola";
	char *str2 = NULL;
	char *str3 = "Hola2";
	list[0] = str1;
	list[1] = str2;
	list[2] = str3;
	
	out = ft_strjoin(3, list, sep);
	printf("%s", out);
	free(out);
}*/
