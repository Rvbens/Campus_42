/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
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
	if (column == 0 || column == x - 1)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	ft_checkmid(int column, int x)
{
	if (column == 0 || column == x - 1)
		ft_putchar('|');
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
			if (row == 0 || row == y - 1)
				ft_check_col(column, x);
			else
				ft_checkmid(column, x);
			column++;
		}
		ft_putchar(10);
		row++;
		column = 0;
	}
}
