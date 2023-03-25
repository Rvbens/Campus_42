/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:16 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/25 19:54:15 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

void	ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2])
{
	c[0] = -grf->scl + 2 * grf->scl / IMG_WIDTH * w + grf->cnt[0];
	c[1] = grf->scl - 2 * grf->scl / IMG_HEIGHT * h + grf->cnt[1];
}

// return number of iterations to escape to infinity or MAX_ITERS
int	ft_mandelbrot(int w, int h, t_graph *grf)
{
	float	c[2];
	float	z[2];
	float	z2[2];
	int		i;

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
int	ft_julia(int w, int h, t_graph *grf, int c[2])
{
	float	z[2];
	float	z2[2];
	int		i;

	ft_pxl_to_coords(w + 0.5, h + 0.5, grf, z);
	z2[0] = c[0] * c[0];
	z2[1] = c[1] * c[1];
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

void	ft_draw_fractal(t_graph *graph)
{
	int	h;
	int	w;
	int	i;

	w = 0;
	while (w < IMG_WIDTH)
	{
		h = 0;
		while (h < IMG_HEIGHT)
		{
			i = ft_mandelbrot(w, h, graph);
			if (i == MAX_ITER)
				mlx_put_pixel((*graph).img, w, h, 0x000000FF);
			else if (i > MAX_ITER / 2)
				mlx_put_pixel((*graph).img, w, h, 0x0000FFFF);
			else if (i > MAX_ITER / 4)
				mlx_put_pixel((*graph).img, w, h, 0x007dFFFF);
			else if (i > MAX_ITER / 10)
				mlx_put_pixel((*graph).img, w, h, 0x00bbFFFF);
			else
				mlx_put_pixel((*graph).img, w, h, 0x00FFFFFF);
			h++;
		}
		w++;
	}
}
