/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:23:55 by rchaves-          #+#    #+#             */
/*   Updated: 2022/11/05 06:00:48 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_print_params(int argn, char **argv)
{
	int	c;

	c = 1;
	while (c < argn)
	{
		while (*argv[c])
			write(1, argv[c]++, 1);
		write(1, &"\n", 1);
		c++;
	}
}

int	main(int argn, char **argv)
{
	int		c;
	int		i;
	int		cmp;
	char	*tmp;

	c = 0;
	while (c < argn - 1)
	{
		i = 1;
		while (i < argn - c - 1)
		{
			cmp = ft_strcmp(argv[i], argv[i + 1]);
			if (cmp > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		c++;
	}
	ft_print_params(argn, argv);
}
