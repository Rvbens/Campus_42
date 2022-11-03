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

#include <unistd.h>

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

void	ft_recursion(long nbr, int base_n, char *base)
{
	if (nbr < 0)
	{
		write(1, &"-", 1);
		nbr *= -1;
	}
	if (nbr > base_n - 1)
		ft_recursion(nbr / base_n, base_n, base);
	write(1, &base[nbr % base_n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_n;

	base_n = 0;
	while (base[base_n])
		base_n++;
	if (base_n > 1 && ft_check_doubles(base))
		ft_recursion(nbr, base_n, base);
}
