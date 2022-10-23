/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:13:18 by dgarizad          #+#    #+#             */
/*   Updated: 2022/10/23 12:26:34 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char character);

void	ft_check_col(int column, int x)
{
	if (column == 0)
		ft_putchar('A');
	else if (column == x - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	ft_last_row(int column, int x)
{
	if (column == 0)
		ft_putchar('C');
	else if (column == x - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	ft_checkmid(int column, int x)
{
	if (column == 0 || column == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	column;
	int	row;

	column = 0;
	row = 0;
	while (row < y)
	{
		while (column < x)
		{
			if (row == 0)
				ft_check_col(column, x);
			else if (row == y - 1)
				ft_last_row(column, x);
			else
				ft_checkmid(column, x);
			column++;
		}
		ft_putchar(10);
		row++;
		column = 0;
	}
}
