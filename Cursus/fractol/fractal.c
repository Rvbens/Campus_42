/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:16 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/13 16:14:01 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

// return number of iterations to escape to infinity or MAX_ITERS
int	ft_mandelbrot(int w, int h, t_graph *grf, float n[2])
{
	float	c[2];
	float	z[2];
	float	z2[2];
	int		i;

	n[1] = 0;
	ft_pxl_to_coords(w + 0.5, h + 0.5, grf, c);
	z2[0] = 0;
	z2[1] = 0;
	z[0] = 0;
	z[1] = 0;
	i = 0;
	while (z2[0] + z2[1] < 4. && i < MAX_ITER)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z2[0] - z2[1] + c[0];
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		i++;
	}
	return (i);
}

// return number of iterations to escape to infinity or MAX_ITERS
int	ft_julia(int w, int h, t_graph *grf, float c[2])
{
	float	z[2];
	float	z2[2];
	int		i;

	ft_pxl_to_coords(w + 0.5, h + 0.5, grf, z);
	z2[0] = z[0] * z[0];
	z2[1] = z[1] * z[1];
	i = 1;
	while (z2[0] + z2[1] < 4. && i < MAX_ITER)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z2[0] - z2[1] + c[0];
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		i++;
	}
	return (i);
}

// Z = Cos(Z)+ 1/C 
// cos(a+bi) = cos(a)*cosh(b) − i sin(a)*sinh(b)
// cosh(b) = (e^b + e^-b) / 2
// sinh(b) = (e^b - e^-b) / 2
int	ft_mandelbrot2(int w, int h, t_graph *grf, float n[2])
{
	float	c[2];
	float	z[2];
	float	e[2];
	float	tmp;
	int		i;

	n[1] = 0;
	ft_pxl_to_coords(w + 0.5, h + 0.5, grf, c);
	tmp = c[0];
	c[0] = c[0] / (c[0] * c[0] + c[1] * c[1]);
	c[1] = -c[1] / (tmp * tmp + c[1] * c[1]);
	z[0] = 0;
	z[1] = 0;
	i = 0;
	while (z[0] + z[1] < 100. && i < MAX_ITER)
	{
		tmp = z[0];
		e[0] = exp(z[1]);
		e[1] = exp(-z[1]);
		z[0] = cos(z[0]) * (e[0] + e[1]) / 2 + c[0];
		z[1] = -sin(tmp) * ((e[0] - e[1])) / 2 + c[1];
		i++;
	}
	return (i);
}

t_frac_fn	ft_id_to_fn(t_graph *grf)
{
	if (grf->fn_id == 2)
		return (&ft_mandelbrot2);
	else if (grf->fn_id == 1)
		return (&ft_julia);
	else
		return (&ft_mandelbrot);
}
