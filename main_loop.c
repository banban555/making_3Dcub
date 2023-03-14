/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:24:06 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 12:05:58 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main_loop(t_all *a)
{
	key_update(a);
	set_background(a);
	calc_wall(a);
	draw(a);
	return (0);
}

void	set_background(t_all *a)
{
	int i;
	int j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (i < HEIGHT / 2)
				a->img.data[i * WIDTH + j] = a->opt.color_c;
			else
				a->img.data[i * WIDTH + j] = a->opt.color_f;
		}
	}
}

void	calc_wall(t_all *a)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		set_data_for_calc(a, x);
		set_step_and_sidedist(a);
		when_hit_is_zero(a);
		when_hit_is_one(a, x);
	}
}
