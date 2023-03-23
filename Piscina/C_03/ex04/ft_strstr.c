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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*s1 && *s2 && i < n - 1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	find_len;
	int	found;

	find_len = 0;
	while (to_find[find_len])
		find_len++;
	if (!find_len)
		return (str);
	found = 0;
	while (*str)
	{
		found = ft_strncmp(str, to_find, find_len) == 0;
		if (found)
			break ;
		str++;
	}
	if (found)
		return (str);
	else
		return (0);
}
