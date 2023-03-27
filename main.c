/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:53 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/27 17:51:04 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //borrar
#include "MLX42/MLX42.h"
#include "fractol.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_set_default_graph(t_graph *graph)
{
	graph->cnt[0] = 0.;
	graph->cnt[1] = 0.;
	graph->scl = 2.;
	graph->fn_param[0] = 0.3;
	graph->fn_param[1] = -0.5;
}

void	my_keyhook(mlx_key_data_t kdt, void *param)
{
	t_graph	*grf;

	grf = ((t_graph *) param);
	if ((kdt.key == MLX_KEY_A || kdt.key == MLX_KEY_LEFT) && kdt.action == 1)
	{
		grf->cnt[0] -= (0.1 * grf->scl);
		ft_draw_fractal(grf);
	}
	else if ((kdt.key == MLX_KEY_D || kdt.key == 262) && kdt.action == 1)
	{
		grf->cnt[0] += (0.1 * grf->scl);
		ft_draw_fractal(grf);
	}
	else if ((kdt.key == MLX_KEY_W || kdt.key == 265) && kdt.action == 1)
	{
		grf->cnt[1] += (0.1 * grf->scl);
		ft_draw_fractal(grf);
	}
	else if ((kdt.key == MLX_KEY_S || kdt.key == 264) && kdt.action == 1)
	{
		grf->cnt[1] -= (0.1 * grf->scl);
		ft_draw_fractal(grf);
	}
	//else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	int32_t	x;
	int32_t	y;
	t_graph	*grf;

	grf = ((t_graph *) param);
	mlx_get_mouse_pos(grf->mlx, &x, &y);
	ft_pxl_to_coords(x, y, grf, grf->cnt);
	if (ydelta > 0)
	{
		grf->scl *= 1.2;
		ft_draw_fractal(grf);
	}
	else if (ydelta < 0)
	{
		grf->scl *= 0.8;
		ft_draw_fractal(grf);
	}
	xdelta *= 1;
}

int32_t	main(int argn, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_graph		graph;

	ft_set_default_graph(&graph);
	if (ft_parse_input(argn, argv, &graph))
		return (EXIT_FAILURE);
	mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "fractol by rchaves-", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	graph.img = img;
	graph.mlx = mlx;
	ft_draw_fractal(&graph);
	mlx_key_hook(mlx, &my_keyhook, &graph);
	mlx_scroll_hook(mlx, &my_scrollhook, &graph);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
