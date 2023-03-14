/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:01:43 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/08 20:31:34 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_position(t_all *a)
{
	int i;
	int j;
	int index;

	index = 0;
	i = -1;
	while (++i < a->map.map_h)
	{
		j = -1;
		while (++j < a->map.map_w)
		{
			index = ft_strchr_idx("NEWS", a->map.final[i][j]);
			if (index >= 0)
			{
				a->map.dir_p = a->map.final[i][j];
				a->pos_x = (double)i + 0.5;
				a->pos_y = (double)j + 0.5;
				return ;
			}
		}
	}
}
