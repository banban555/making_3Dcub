/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:36:30 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 17:14:40 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_data_for_calc(t_all *a, int x)
{
	a->cal.cam_x = 2 * x / (double)WIDTH - 1;
	a->cal.ray_x = a->dir_x + a->plane_x * a->cal.cam_x;
	a->cal.ray_y = a->dir_y + a->plane_y * a->cal.cam_x;
	a->cal.map_x = (int)a->pos_x;
	a->cal.map_y = (int)a->pos_y;
	a->cal.ddist_x = fabs(1 / a->cal.ray_x);
	a->cal.ddist_y = fabs(1 / a->cal.ray_y);
	a->cal.hit = 0;
}

void	set_step_and_sidedist(t_all *a)
{
	if (a->cal.ray_x < 0)
	{
		a->cal.step_x = -1;
		a->cal.sdist_x =
			(a->pos_x - a->cal.map_x) * a->cal.ddist_x;
	}
	else
	{
		a->cal.step_x = 1;
		a->cal.sdist_x =
			(a->cal.map_x + 1.0 - a->pos_x) * a->cal.ddist_x;
	}
	if (a->cal.ray_y < 0)
	{
		a->cal.step_y = -1;
		a->cal.sdist_y =
			(a->pos_y - a->cal.map_y) * a->cal.ddist_y;
	}
	else
	{
		a->cal.step_y = 1;
		a->cal.sdist_y =
			(a->cal.map_y + 1.0 - a->pos_y) * a->cal.ddist_y;
	}
}

void	set_data_for_pick_1(t_all *a)
{
	if (a->cal.side == 0)
		a->cal.pwdist = (a->cal.map_x - a->pos_x +
							(1 - a->cal.step_x) / 2) / a->cal.ray_x;
	else
		a->cal.pwdist = (a->cal.map_y - a->pos_y +
							(1 - a->cal.step_y) / 2) / a->cal.ray_y;
	a->cal.line_h = (int)(HEIGHT / a->cal.pwdist);
	a->cal.d_start = -a->cal.line_h / 2 + HEIGHT / 2;
	if (a->cal.d_start < 0)
		a->cal.d_start = 0;
	a->cal.d_end = a->cal.line_h / 2 + HEIGHT / 2;
	if (a->cal.d_end >= HEIGHT)
		a->cal.d_end = HEIGHT - 1;
}

void	set_data_for_pick_2(t_all *a)
{
	if (a->cal.side == 0)
		a->cal.wall_x = a->pos_y +
						a->cal.pwdist * a->cal.ray_y;
	else
		a->cal.wall_x = a->pos_x +
						a->cal.pwdist * a->cal.ray_x;
	a->cal.wall_x -= floor((a->cal.wall_x));
	a->cal.tex_x = (int)(a->cal.wall_x * (double)a->img.img_w);
	if (a->cal.side == 0 && a->cal.ray_x > 0)
		a->cal.tex_x = a->img.img_w - a->cal.tex_x - 1;
	if (a->cal.side == 1 && a->cal.ray_y < 0)
		a->cal.tex_x = a->img.img_w - a->cal.tex_x - 1;
	a->cal.step = 1.0 * a->img.img_h / a->cal.line_h;
	a->cal.tex_p = (a->cal.d_start - HEIGHT / 2 +
						a->cal.line_h / 2) * a->cal.step;
}

void	set_texture_idx(t_all *a)
{
	if (a->cal.ray_x < 0 && a->cal.side == 0)
		a->idx_tex = S;
	else if (a->cal.ray_y > 0 && a->cal.side == 1)
		a->idx_tex = W;
	else if (a->cal.ray_y < 0 && a->cal.side == 1)
		a->idx_tex = E;
	else if (a->cal.ray_x > 0 && a->cal.side == 0)
		a->idx_tex = N;
}
