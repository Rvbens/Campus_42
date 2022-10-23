/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:13:18 by dgarizad          #+#    #+#             */
/*   Updated: 2022/10/23 12:10:45 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
			{
				if (c == 0)
				{
					ft_putchar('/');
				}
				else if (c == cols - 1)
				{
					ft_putchar('\\');
				}
				else
				{
					ft_putchar('*');
				}
			}
			else if (f == fils - 1)
			{
				if (c == 0)
				{
					ft_putchar('\\');
				}
				else if (c == cols - 1)
				{
					ft_putchar('/');
				}
				else
				{
					ft_putchar('*');
				}
			}
			else
			{
				if (c == 0 || c == cols - 1)
				{
					ft_putchar('*');
				}
				else
				{
					ft_putchar(' ');
				}
			}
			c++;
		}
		ft_putchar(10);
		f++;
		c = 0;
	}
}

int	main(void)
{
	rush(5,3);
	rush(5,1);
	rush(1,1);
	rush(1,5);
	rush(10,5);
	return(0);
}
