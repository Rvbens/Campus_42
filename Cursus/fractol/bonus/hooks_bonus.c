/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:02:44 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/14 16:14:31 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol_bonus.h"

void	ft_move_kh(mlx_key_data_t kdt, t_graph *grf)
{
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
}

void	ft_more_kh(mlx_key_data_t kdt, t_graph *grf)
{
	if (kdt.key == MLX_KEY_ESCAPE && kdt.action == MLX_PRESS)
	{
		exit(0);
	}
	else if (kdt.key == MLX_KEY_Z && kdt.action == MLX_PRESS)
	{
		grf->scl *= 0.8;
		ft_draw_fractal(grf);
	}
	else if (kdt.key == MLX_KEY_X && kdt.action == MLX_PRESS)
	{
		grf->scl *= 1.2;
		ft_draw_fractal(grf);
	}
	else if (kdt.key == MLX_KEY_R && kdt.action == MLX_PRESS)
	{
		grf->cnt[0] = 0;
		grf->cnt[1] = 0;
		ft_draw_fractal(grf);
	}
}

void	ft_my_keyhook(mlx_key_data_t kdt, void *param)
{
	t_graph	*grf;

	grf = ((t_graph *) param);
	ft_move_kh(kdt, grf);
	ft_more_kh(kdt, grf);
}

void	ft_my_scrollhook(double xdelta, double ydelta, void *param)
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
