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

void	ft_col_1(int c, int cols)
{
	if (c == 0)
		ft_putchar('/');
	else if (c == cols - 1)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	ft_fil_ult(int c, int cols)
{
	if (c == 0)
		ft_putchar('\\');
	else if (c == cols - 1)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	ft_resto(int c, int cols)
{
	if (c == 0 || c == cols - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int cols, int fils)
{
	int	c;
	int	f;

	c = 0;
	f = 0;
	while (f < fils)
	{
		while (c < cols)
		{
			if (f == 0)
				ft_col_1(c, cols);
			else if (f == fils - 1)
				ft_fil_ult(c, cols);
			else
				ft_resto(c, cols);
			c++;
		}
		ft_putchar(10);
		f++;
		c = 0;
	}
}
