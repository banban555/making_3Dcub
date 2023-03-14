/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:48:19 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/22 14:02:54 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_tex(t_all *a)
{
	int i;

	i = -1;
	a->tex = (int **)ft_calloc(4, sizeof(int *));
	if (!a->tex)
		print_error(a, "from malloc_tex: wrong malloc");
	while (++i < 4)
	{
		a->tex[i] = (int *)ft_calloc(sizeof(int), 64 * 64);
		if (!a->tex[i])
		{
			free_int_arrays(i, a->tex);
			print_error(a, "from malloc_tex: wrong malloc");
		}
	}
}

void	malloc_map_draft(t_all *a)
{
	a->map.draft = (char *)ft_calloc(sizeof(char), 1);
	if (!a->map.draft)
		print_error(a, "from malloc_map_draft: wrong malloc");
}

void	malloc_map_final(t_all *a)
{
	int i;

	i = -1;
	a->map.final = (char **)ft_calloc(sizeof(char *), a->map.map_h + 1);
	if (!a->map.final)
		print_error(a, "from malloc_map_final: wrong malloc");
	while (++i < a->map.map_h)
	{
		a->map.final[i] = (char *)ft_calloc(sizeof(char), a->map.map_w + 1);
		if (!a->map.final[i])
		{
			free_char_arrays(i, a->map.final);
			print_error(a, "from malloc_map_final: wrong malloc");
		}
	}
}

void	malloc_map_copy(t_all *a)
{
	int i;

	i = -1;
	a->map.copy = (char **)ft_calloc(sizeof(char *), a->map.map_h + 1);
	if (!a->map.copy)
		print_error(a, "from malloc_map_copy: wrong malloc");
	while (++i < a->map.map_h)
	{
		a->map.copy[i] = (char *)ft_calloc(sizeof(char), a->map.map_w + 1);
		if (!a->map.copy[i])
		{
			free_char_arrays(i, a->map.copy);
			print_error(a, "from malloc_map_copy: wrong malloc");
		}
	}
}
