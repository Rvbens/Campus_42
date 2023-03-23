/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:46:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/10 14:09:49 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	base_n;

	base_n = 0;
	while (base[base_n])
		base_n++;
	if (base_n < 2)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		i = 0;
		while (base[i++])
		{
			if (*base == base[i])
				return (0);
		}
		base++;
	}
	return (base_n);
}

int	ft_char_to_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{	
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sig;
	int	out;
	int	base_n;

	base_n = ft_check_base(base);
	if (!base_n)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sig = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	out = 0;
	while (ft_char_to_base(str[0], base) != -1)
		out = out * base_n + ft_char_to_base(str++[0], base);
	return (sig * out);
}
