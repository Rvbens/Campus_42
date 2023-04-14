/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaves- <rchaves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:53:26 by rchaves-          #+#    #+#             */
/*   Updated: 2023/04/14 11:51:27 by rchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pxl_to_coords(int w, int h, t_graph *grf, float c[2])
{
	c[0] = -grf->scl + 2 * grf->scl / IMG_WIDTH * w + grf->cnt[0];
	c[1] = grf->scl - 2 * grf->scl / IMG_HEIGHT * h + grf->cnt[1];
}

int	ft_iter_to_grad(int i, int min)
{
	float	p;
	int		max;
	float	from;

	if (i == MAX_ITER)
		return (0x000000FF);
	i -= min;
	if (i < 0)
		i = 0;
	max = MAX_ITER - min;
	if (i < (max / 3))
		return (0x000000FF | ((int)(i / (max / 3.) * 256.) << 8));
	else if (i < (2 * max / 3))
	{
		from = max / 3;
		p = (i - from) / (2 * max / 3. - from) * 256;
		return (0x0000FFFF | ((int)(p) << 24));
	}
	else
	{
		from = 2 * max / 3;
		p = (i - from) / (max - from) * 256;
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

void	ft_draw_fractal(t_graph *grf)
{
	t_frac_fn	fn;
	t_iter		iter;
	int			nxt_min;
	int			*pxls;
	char		*pxl;

	fn = ft_id_to_fn(grf);
	iter.w = 0;
	pxls = (int *) grf->img->pixels;
	nxt_min = MAX_ITER;
	while (iter.w < IMG_WIDTH)
	{
		iter.h = 0;
		while (iter.h < IMG_HEIGHT)
		{
			iter.i = fn(iter.w, iter.h, grf, grf->fn_param);
			if (iter.i < nxt_min)
				nxt_min = iter.i;
				pxl = (char *) &pxls[iter.h * IMG_WIDTH + iter.w];
			ft_reverse_pxl(pxl, ft_iter_to_grad(iter.i, grf->lst_min));
			iter.h++;
		}
		iter.w++;
	}
	grf->lst_min = nxt_min;
}
