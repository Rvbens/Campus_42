/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:43:47 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/27 19:48:41 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "unistd.h"
#include "libft.h"
#include "fractol.h"

float	ft_atof(const char *str)
{
	float	sig;
	float	out;
	float	dec;
	float	exp;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sig = 1;
	if (*str == '-' || *str == '+')
		sig -= 2 * (*str++ == '-');
	out = 0;
	while (*str >= '0' && *str <= '9')
		out = out * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	dec = 0;
	exp = 1;
	while (*str >= '0' && *str <= '9')
	{	
		exp *= 10;
		dec += (*str++ - '0') / exp;
	}
	return (sig * out + dec);
}

int	ft_parse_float(char *argv, float *param)
{
	*param = ft_atof(argv);
	return (0);
}

int	ft_parse_julia(int argn, char **argv, t_graph	*graph)
{
	if (argn != 4)
	{
		write(1, "Invalid arguments. Ex: julia 0.5 -0.1\n", 39);
		return (1);
	}
	graph->fn_id = 1;
	if (ft_parse_float(argv[2], &(graph->fn_param[0])))
	{
		write(1, "Invalid real float\n", 39);
		return (1);
	}
	if (ft_parse_float(argv[3], &(graph->fn_param[1])))
	{
		write(1, "Invalid imaginary float\n", 39);
		return (1);
	}
	return (0);
}

int	ft_parse_input(int argn, char **argv, t_graph	*graph)
{
	if (argn == 1)
	{
		write(1, "No fractal selected from: mandelbrot, julia.\n", 46);
		return (1);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 12) == 0 && argn == 2)
		graph->fn_id = 0;
	else if (ft_strncmp(argv[1], "julia", 12) == 0)
	{
		return (ft_parse_julia(argn, argv, graph));
	}
	else
	{
		write(1, "Invalid number of arguments.\n", 30);
		return (1);
	}
	return (0);
}
