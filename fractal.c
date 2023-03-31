/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:16 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/31 20:21:28 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

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

int	ft_mandelbrot2(int w, int h, t_graph *grf, float n[2]);

t_frac_fn	ft_id_to_fn(t_graph *grf)
{
	if (grf->fn_id == 0)
		return (&ft_mandelbrot);
	else //if (grf->fn_id == 1)
		return (&ft_julia);
}
