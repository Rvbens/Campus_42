/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:31:03 by rchaves-          #+#    #+#             */
/*   Updated: 2022/10/21 11:59:04 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[5];

	comb[0] = '0';
	comb[1] = '1';
	comb[2] = '2';
	comb[3] = ',';
	comb[4] = ' ';
	while (comb[0] < '7')
	{
		while (comb[1] < '9')
		{
			while (comb[2] <= '9')
			{
				write(1, &comb, 5);
				comb[2]++;
			}
			comb[1]++;
			comb[2] = comb[1] + 1;
		}
		comb[0]++;
		comb[1] = comb[0] + 1;
		comb[2] = comb[0] + 2;
	}
	write(1, &comb, 3);
}
