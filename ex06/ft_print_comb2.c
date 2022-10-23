/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:31:03 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/21 22:32:42 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_int(int par)
{
	char	out[2];

	out[0] = par / 10 + 48;
	out[1] = par % 10 + 48;
	write(1, &out, 2);
}

void	ft_print_comb2(void)
{
	int		par1;
	int		par2;
	char	sep[2];

	par1 = 0;
	par2 = 1;
	sep[0] = ',';
	sep[1] = ' ';
	while (par1 < 99)
	{
		while (par2 < 100)
		{
			ft_print_int(par1);
			write(1, &sep[1], 1);
			ft_print_int(par2);
			if (par1 != 98 || par2 != 99)
			{
				write(1, &sep, 2);
			}
			par2++;
		}
		par1++;
		par2 = par1 + 1;
	}
}
