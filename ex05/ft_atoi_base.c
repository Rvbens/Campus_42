/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:46:04 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/28 11:46:07 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_doubles(char *base)
{
	int	i;

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
	return (1);
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

int	ft_save_digits(char *str, int *arr, char *base)
{
	int		i;
	char	c;

	i = 0;
	c = ft_char_to_base(str[0], base);
	while (c >= 0)
	{
		arr[i] = c;
		i++;
		c = ft_char_to_base(str[i], base);
	}
	return (i);
}

int	ft_arr_to_int(int *arr, int i, int base_n)
{
	int	out;
	int	exp;

	out = 0;
	exp = 1;
	while (i--)
	{
		out += arr[i] * exp;
		exp *= base_n;
	}
	return (out);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sig;
	int	arr[32];
	int	i;
	int	out;
	int	base_n;

	base_n = 0;
	while (base[base_n])
		base_n++;
	if (base_n < 2 || !ft_check_doubles(base))
		return (0);
	while (*str == '\t' | *str == '\n' | *str == '\v'
		| *str == '\r' | *str == ' ' | *str == '\f')
		str++;
	sig = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	i = ft_save_digits(str, arr, base);
	out = ft_arr_to_int(arr, i, base_n);
	return (sig * out);
}
