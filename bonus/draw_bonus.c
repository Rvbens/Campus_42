/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:53:26 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/14 16:14:22 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2])
{
	c[0] = -grf->scl + 2 * grf->scl / IMG_WIDTH * w + grf->cnt[0];
	c[1] = grf->scl - 2 * grf->scl / IMG_HEIGHT * h + grf->cnt[1];
}

// in set = black
// low iter: black - blue
// mid iter: blue - pruple
// almost in set: purple - white
int	ft_iter_to_grad(int i, t_graph *grf)
{
	float	p;
	int		rng;
	float	from;

	if (i == MAX_ITER)
		return (0x000000FF);
	i -= grf->lst_min;
	if (i < 0)
		i = 0;
	rng = grf->lst_max - grf->lst_min;
	if (i < (rng / 3))
		return (0x000000FF | ((int)(i / (rng / 3.) * 256.) << 8));
	else if (i < (2 * rng / 3))
	{
		from = rng / 3;
		p = (i - from) / (2 * rng / 3. - from) * 256.;
		return (0x0000FFFF | ((int)(p) << 24));
	}
	else
	{
		from = 2 * rng / 3;
		p = (i - from) / (rng - from) * 256.;
		return (0xFF00FFFF | ((int)(p) << 16));
	}
}

//reverse endianess
void	ft_reverse_pxl(char *pxl, int clr)
{
	*(pxl++) = (char)(clr >> 24);
	*(pxl++) = (char)(clr >> 16);
	*(pxl++) = (char)(clr >> 8);
	*(pxl++) = (char)(clr & 0xFF);
}

typedef struct s_iter {
	int			h;
	int			w;
	int			i;
}	t_iter;

void	ft_set_min_max(t_graph *grf)
{
	grf->lst_min = grf->nxt_min;
	grf->lst_max = grf->nxt_max;
	grf->nxt_min = MAX_ITER;
	grf->nxt_max = 0;
}

void	ft_draw_fractal(t_graph *grf)
{
	t_frac_fn	fn;
	t_iter		iter;
	int			*pxls;
	char		*pxl;

	fn = ft_id_to_fn(grf);
	iter.w = 0;
	pxls = (int *) grf->img->pixels;
	ft_set_min_max(grf);
	while (iter.w < IMG_WIDTH)
	{
		iter.h = 0;
		while (iter.h < IMG_HEIGHT)
		{
			iter.i = fn(iter.w, iter.h, grf, grf->fn_param);
			if (iter.i < grf->nxt_min)
				grf->nxt_min = iter.i;
			if (iter.i > grf->nxt_max && iter.i != MAX_ITER)
				grf->nxt_max = iter.i;
			pxl = (char *) &pxls[iter.h * IMG_WIDTH + iter.w];
			ft_reverse_pxl(pxl, ft_iter_to_grad(iter.i, grf));
			iter.h++;
		}
		iter.w++;
	}
}
