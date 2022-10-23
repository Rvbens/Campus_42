/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:13:18 by dgarizad          #+#    #+#             */
/*   Updated: 2022/10/23 12:26:34 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char character);

void	ft_col_1(int c, int x)
{
	if (c == 0)
		ft_putchar('A');
	else if (c == x - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	ft_fil_ult(int c, int x)
{
	if (c == 0)
		ft_putchar('A');
	else if (c == x - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	ft_resto(int c, int x)
{
	if (c == 0 || c == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	c;
	int	f;

	c = 0;
	f = 0;
	while (f < y)
	{
		while (c < x)
		{
			if (f == 0)
				ft_col_1(c, x);
			else if (f == y - 1)
				ft_fil_ult(c, x);
			else
				ft_resto(c, x);
			c++;
		}
		ft_putchar(10);
		f++;
		c = 0;
	}
}
