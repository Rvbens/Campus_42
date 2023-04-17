/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/17 18:26:16 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// arg not int, arg > int, check duplicates
int	ft_check_input(char **argv)
{
	(void) argv;
	return (1);
}

int	main(int argn, char **argv)
{
	int	*stk_a;
	int	*stk_b;

	if (!ft_check_input(argv))
	{	
		ft_printf("Error\n");
		return (1);
	}
	stk_a = malloc(argn - 1);
	stk_b = malloc(argn - 1);
	return (0);
}
