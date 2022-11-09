/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:21:02 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/09 22:44:43 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		write(1, &"-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}


void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].size != 0)
	{
		j = 0;
		while (par[i].str[j])
			write(1, &par[i].str[j++], 1);
		write(1, &"\n", 1);
		ft_putnbr(par[i].size);
		write(1, &"\n", 1);
		j = 0;
		while (par[i].copy[j])
			write(1, &par[i].copy[j++], 1);
		write(1, &"\n", 1);
		i++;
	}
}


/*#include <stdio.h>
int	main(void)
{
	t_stock_str	*stk;
	char		*list[2];
	char		*str1 = "Hola1";
	char		str2[] = "Hola2";

	list[0] = str1;
	list[1] = &str2[0];
	stk = ft_strs_to_tab(2, list);
	ft_show_tab(stk);
}*/
