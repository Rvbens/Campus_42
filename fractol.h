/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:46:59 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/27 17:32:31 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define IMG_WIDTH 512
# define IMG_HEIGHT 512
# define MAX_ITER 64

typedef struct s_graph {
	mlx_image_t	*img;
	mlx_t		*mlx;
	float		cnt[2];
	float		scl;
	int			fn_id;
	float		fn_param[2];
}	t_graph;

int		ft_parse_input(int argn, char **argv, t_graph *graph);

int		ft_mandelbrot(int w, int h, t_graph *grf, float n[2]);

void	ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2]);

void	ft_draw_fractal(t_graph *graph);

#endif