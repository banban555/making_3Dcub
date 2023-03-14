/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:12:19 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/18 11:53:58 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_info(t_all *a, char *line)
{
	check_line_full_option(a);
	if (line[0] == 0 && a->map_part <= 0)
		return ;
	else if ((ft_strchr_idx(" 01", line[0]) >= 0) && a->opt.full == 1)
	{
		check_wrong_line_input(a, line);
		a->map_part = 1;
		check_map(a, line);
	}
	else if ((line[0] == 0) && a->map_part == 1)
		a->map_part = -1;
	else if (ft_strchr_idx("NEWS", line[0]) >= 0 && a->opt.full == 0)
		check_wall_path(a, line);
	else if ((ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
			&& a->opt.full == 0)
		check_rgb_by_comma(a, line);
	else
	{
		free(line);
		print_error(a, "from check_line_info: wrong option");
	}
}

void	check_line_full_option(t_all *a)
{
	if (a->opt.no == 1
	&& a->opt.so == 1
	&& a->opt.we == 1
	&& a->opt.ea == 1
	&& a->opt.f == 1
	&& a->opt.c == 1)
		a->opt.full = 1;
}

void	check_wrong_line_input(t_all *a, char *line)
{
	if (a->map_part < 0)
	{
		free(line);
		print_error(a, "from check_wrong_line_input: wrong line");
	}
}
