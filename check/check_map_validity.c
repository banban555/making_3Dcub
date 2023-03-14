/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:16:34 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 16:45:14 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_copy(t_all *a)
{
	int x;
	int y;

	x = (int)a->pos_x;
	y = (int)a->pos_y;
	check_by_dfs(a, x, y);
	free_char_arrays(a->map.map_h + 1, a->map.copy);
	a->map.copy = NULL;
}

void	check_by_dfs(t_all *a, int x, int y)
{
	int	i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	if (a->map.copy[x][y] == '.')
		return ;
	a->map.copy[x][y] = '.';
	while (++i < 4)
	{
		j = set_a(i, x);
		k = set_b(i, y);
		error_or_dfs(a, j, k);
	}
}

int		set_a(int i, int x)
{
	if (i == 0)
		return (x - 1);
	else if (i == 1)
		return (x + 1);
	else if (i == 2)
		return (x);
	else if (i == 3)
		return (x);
	return (0);
}

int		set_b(int i, int y)
{
	if (i == 0)
		return (y);
	else if (i == 1)
		return (y);
	else if (i == 2)
		return (y - 1);
	else if (i == 3)
		return (y + 1);
	return (0);
}

void	error_or_dfs(t_all *a, int j, int k)
{
	if (j == -1 || j >= a->map.map_h || k == -1 ||
	k >= a->map.map_w)
		print_error(a, "from error_or_dfs: not closed wall");
	if (a->map.copy[j][k] == '7')
		print_error(a, "from error_or_dfs: not closed wall");
	if (a->map.copy[j][k] == '0')
		check_by_dfs(a, j, k);
}
