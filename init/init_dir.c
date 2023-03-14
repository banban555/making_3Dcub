/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:36:27 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/18 11:37:19 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(t_all *a)
{
	init_dir_ns(a);
	init_dir_we(a);
}

void	init_dir_ns(t_all *a)
{
	if (a->map.dir_p == 'N')
	{
		a->dir_x = -1.0;
		a->dir_y = 0.0;
		a->plane_x = 0.0;
		a->plane_y = 0.66;
	}
	else if (a->map.dir_p == 'S')
	{
		a->dir_x = 1.0;
		a->dir_y = 0.0;
		a->plane_x = 0.0;
		a->plane_y = -0.66;
	}
}

void	init_dir_we(t_all *a)
{
	if (a->map.dir_p == 'W')
	{
		a->dir_x = 0.0;
		a->dir_y = -1.0;
		a->plane_x = -0.66;
		a->plane_y = 0.0;
	}
	else if (a->map.dir_p == 'E')
	{
		a->dir_x = 0.0;
		a->dir_y = 1.0;
		a->plane_x = 0.66;
		a->plane_y = 0.0;
	}
}
