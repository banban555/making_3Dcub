/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:25:48 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 14:53:31 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_all *a, char *line)
{
	int i;

	i = 0;
	while (line[++i])
	{
		if (ft_strchr_idx("NEWS", line[i]) >= 0)
			++a->map.num_p;
		if (a->map.num_p >= 2 || ft_strchr_idx(" 01NEWS", line[i]) < 0)
		{
			free(line);
			print_error(a, "from check_map: wrong map");
		}
	}
	++a->map.map_h;
	if (i > a->map.map_w)
		a->map.map_w = i;
	make_map_draft(a, line);
}

void	check_map_final(t_all *a)
{
	int i;
	int j;

	i = -1;
	check_player_position(a);
	malloc_map_copy(a);
	while (++i < a->map.map_h)
	{
		j = -1;
		while (++j < a->map.map_w)
		{
			a->map.copy[i][j] = a->map.final[i][j];
		}
		a->map.copy[i][j] = '\0';
	}
	check_map_copy(a);
}
