/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_by_hit_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:22:13 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/02 13:58:48 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	when_hit_is_zero(t_all *a)
{
	while (a->cal.hit == 0)
	{
		if (a->cal.sdist_x < a->cal.sdist_y)
		{
			a->cal.sdist_x += a->cal.ddist_x;
			a->cal.map_x += a->cal.step_x;
			a->cal.side = 0;
		}
		else
		{
			a->cal.sdist_y += a->cal.ddist_y;
			a->cal.map_y += a->cal.step_y;
			a->cal.side = 1;
		}
		if (a->map.final[a->cal.map_x][a->cal.map_y] == '1')
			a->cal.hit = 1;
	}
}

void	when_hit_is_one(t_all *a, int x)
{
	int y;

	set_data_for_pick_1(a);
	set_data_for_pick_2(a);
	set_texture_idx(a);
	y = a->cal.d_start - 1;
	while (++y < a->cal.d_end)
	{
		a->cal.tex_y = (int)a->cal.tex_p & (a->img.img_h - 1);
		a->cal.tex_p += a->cal.step;
		a->img.data[y * WIDTH + x] = a->tex[a->idx_tex]
								[a->img.img_h * a->cal.tex_y + a->cal.tex_x];
	}
}
