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

int	ft_isspace(char c)
{
	int		isspace;

	isspace = c == '\t' | c == '\n' | c == '\v';
	isspace |= c == '\r' | c == ' ' | c == '\f';
	return (isspace);
}

int	ft_save_digits(char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i] > '0' && str[i] < '9')
	{
		arr[i] = str[i] - '0';
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	sig;
	int	arr[10];
	int	i;
	int	out;
	int	exp;

	sig = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	i = ft_save_digits(str, arr);
	out = 0;
	exp = 1;
	while (i--)
	{
		out += arr[i] * exp;
		exp *= 10;
	}
	return (sig * out);
}
