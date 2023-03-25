/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:46:59 by rchaves-          #+#    #+#             */
/*   Updated: 2023/03/25 19:56:12 by rchaves-         ###   ########.fr       */
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
	
}	t_graph;

void	ft_draw_fractal(t_graph *graph);

void	ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2]);

#endif