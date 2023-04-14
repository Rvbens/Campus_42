/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:17:53 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/14 15:49:46 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fractol.h"

// Exit the program as failure.
static void	ft_error(void)
{
	write(1, "Failed to initiante mlx or img.\n", 33);
	exit(EXIT_FAILURE);
}

void	ft_set_default_graph(t_graph *graph)
{
	graph->cnt[0] = 0.;
	graph->cnt[1] = 0.;
	graph->scl = 2.;
	graph->fn_param[0] = 0.;
	graph->fn_param[1] = 0.;
	graph->nxt_min = 0;
	graph->nxt_max = MAX_ITER;
}

int32_t	main(int argn, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_graph		graph;

	ft_set_default_graph(&graph);
	if (ft_parse_input(argn, argv, &graph))
		return (EXIT_FAILURE);
	mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "Fractol by rchaves-", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	graph.img = img;
	graph.mlx = mlx;
	ft_draw_fractal(&graph);
	mlx_key_hook(mlx, &ft_my_keyhook, &graph);
	mlx_scroll_hook(mlx, &ft_my_scrollhook, &graph);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
