/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:47:55 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/01 14:10:07 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_rotate(t_all *a)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = a->dir_x;
	old_plane_x = a->plane_x;
	key_right(a, old_dir_x, old_plane_x);
	key_left(a, old_dir_x, old_plane_x);
}

void	key_right(t_all *a, double old_dir_x, double old_plane_x)
{
	if (a->key.k_right && !a->key.k_left)
	{
		a->dir_x = a->dir_x * cos(-a->key.r_speed) -
						a->dir_y * sin(-a->key.r_speed);
		a->dir_y = old_dir_x * sin(-a->key.r_speed) +
						a->dir_y * cos(-a->key.r_speed);
		a->plane_x = a->plane_x * cos(-a->key.r_speed) -
						a->plane_y * sin(-a->key.r_speed);
		a->plane_y = old_plane_x * sin(-a->key.r_speed) +
						a->plane_y * cos(-a->key.r_speed);
	}
}

void	key_left(t_all *a, double old_dir_x, double old_plane_x)
{
	if (a->key.k_left && !a->key.k_right)
	{
		a->dir_x = a->dir_x * cos(a->key.r_speed) -
						a->dir_y * sin(a->key.r_speed);
		a->dir_y = old_dir_x * sin(a->key.r_speed) +
						a->dir_y * cos(a->key.r_speed);
		a->plane_x = a->plane_x * cos(a->key.r_speed) -
						a->plane_y * sin(a->key.r_speed);
		a->plane_y = old_plane_x * sin(a->key.r_speed) +
						a->plane_y * cos(a->key.r_speed);
	}
}
