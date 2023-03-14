/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:56:08 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/18 13:54:20 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_abcd(t_all *a, double num[])
{
	if (a->dir_x >= 0)
		num[0] = 0.4;
	if (a->dir_x < 0)
		num[0] = -0.4;
	if (a->dir_y >= 0)
		num[1] = 0.4;
	if (a->dir_y < 0)
		num[1] = -0.4;
	if (a->plane_x >= 0)
		num[2] = 0.4;
	if (a->plane_x < 0)
		num[2] = -0.4;
	if (a->plane_y >= 0)
		num[3] = 0.4;
	if (a->plane_y < 0)
		num[3] = -0.4;
}

void	key_ws(t_all *a, double num[])
{
	if (a->key.k_w)
	{
		if (a->map.final[(int)(a->pos_x + a->dir_x *
		(a->key.m_speed) + num[0])][(int)(a->pos_y)] != '1')
			a->pos_x += a->dir_x * (a->key.m_speed);
		if (a->map.final[(int)(a->pos_x)][(int)(a->pos_y +
		(a->dir_y * a->key.m_speed) + num[1])] != '1')
			a->pos_y += a->dir_y * (a->key.m_speed);
	}
	if (a->key.k_s)
	{
		if (a->map.final[(int)(a->pos_x - a->dir_x *
		a->key.m_speed - num[0])][(int)(a->pos_y)] != '1')
			a->pos_x -= a->dir_x * a->key.m_speed;
		if (a->map.final[(int)(a->pos_x)][(int)(a->pos_y -
		a->dir_y * a->key.m_speed - num[1])] != '1')
			a->pos_y -= a->dir_y * a->key.m_speed;
	}
}

void	key_ad(t_all *a, double num[])
{
	if (a->key.k_a)
	{
		if (a->map.final[(int)(a->pos_x - a->plane_x *
		a->key.m_speed - num[2])][(int)(a->pos_y)] != '1')
			a->pos_x -= a->plane_x * a->key.m_speed;
		if (a->map.final[(int)(a->pos_x)][(int)(a->pos_y -
		a->plane_y * a->key.m_speed - num[3])] != '1')
			a->pos_y -= a->plane_y * a->key.m_speed;
	}
	if (a->key.k_d)
	{
		if (a->map.final[(int)(a->pos_x + a->plane_x *
		a->key.m_speed + num[2])][(int)(a->pos_y)] != '1')
			a->pos_x += a->plane_x * a->key.m_speed;
		if (a->map.final[(int)(a->pos_x)][(int)(a->pos_y +
		a->plane_y * a->key.m_speed + num[3])] != '1')
			a->pos_y += a->plane_y * a->key.m_speed;
	}
}
