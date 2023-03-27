/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:16 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/27 17:35:20 by rchaves-         ###   ########.fr       */
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

int	ft_iter_to_color(int i)
{
	if (i == MAX_ITER)
		return (0x000000FF);
	else if (i > MAX_ITER / 2)
		return (0x0000FFFF);
	else if (i > MAX_ITER / 4)
		return (0x007dFFFF);
	else if (i > MAX_ITER / 10)
		return (0x00bbFFFF);
	else
		return (0x00FFFFFF);
}

void	ft_draw_fractal(t_graph *graph)
{
	static int	(*fn)(int, int, t_graph*, float*);
	int			h;
	int			w;
	int			i;

	if (graph->fn_id == 0)
		fn = &ft_mandelbrot;
	else if (graph->fn_id == 1)
		fn = &ft_julia;
	w = 0;
	while (w < IMG_WIDTH)
	{
		h = 0;
		while (h < IMG_HEIGHT)
		{
			i = fn(w, h, graph, graph->fn_param);
			mlx_put_pixel(graph->img, w, h, ft_iter_to_color(i));
			h++;
		}
		w++;
	}
}
