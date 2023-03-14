/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:34:19 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/18 11:36:49 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_final(t_all *a, char **map_second)
{
	int i;
	int j;

	i = -1;
	while (++i < a->map.map_h)
	{
		j = -1;
		while (++j < a->map.map_w && map_second[i][j] != '\0')
		{
			if (map_second[i][j] == ' ')
				a->map.final[i][j] = '7';
			else if (map_second[i][j])
				a->map.final[i][j] = map_second[i][j];
		}
		while (j < a->map.map_w)
		{
			a->map.final[i][j] = '7';
			++j;
		}
		a->map.final[i][j] = '\0';
	}
}
