/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:08:02 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/18 11:34:54 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_map_draft(t_all *a, char *line)
{
	char *tmp;

	tmp = ft_strjoin_change_null(a->map.draft, line);
	if (a->map.draft)
		free(a->map.draft);
	if (!tmp)
	{
		free(line);
		print_error(a, "from make_map_draft: wrong map");
	}
	a->map.draft = tmp;
}

void	make_map_final(t_all *a)
{
	char **map_second;

	if (a->map.num_p == 0)
		print_error(a, "from make_map_final: wrong map");
	malloc_map_final(a);
	map_second = ft_split(a->map.draft, 'a');
	free(a->map.draft);
	a->map.draft = NULL;
	save_map_final(a, map_second);
	free_char_arrays(a->map.map_h, map_second);
	check_map_final(a);
}
