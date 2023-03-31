/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:46:59 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/31 20:20:03 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define IMG_WIDTH 512
# define IMG_HEIGHT 512
# define MAX_ITER 128
# include "MLX42/MLX42.h"

typedef struct s_graph {
	mlx_image_t	*img;
	mlx_t		*mlx;
	float		cnt[2];
	float		scl;
	int			fn_id;
	float		fn_param[2];
	int			lst_min;
}	t_graph;

typedef int	(*t_frac_fn)(int, int, t_graph*, float*);

int			ft_parse_input(int argn, char **argv, t_graph *graph);

void		ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2]);

void		ft_draw_fractal(t_graph *graph);

t_frac_fn	ft_id_to_fn(t_graph *grf);

void		ft_my_keyhook(mlx_key_data_t kdt, void *param);

void		ft_my_scrollhook(double xdelta, double ydelta, void *param);

#endif