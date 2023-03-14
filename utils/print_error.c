/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:21:33 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 18:26:19 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(t_all *a, char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	free_all(a);
	exit(1);
}

void	free_all(t_all *a)
{
	if (a->tex)
		free_int_arrays(4, a->tex);
	if (a->map.draft)
		free(a->map.draft);
	if (a->map.copy)
		free_char_arrays(a->map.map_h + 1, a->map.copy);
	if (a->map.final)
		free_char_arrays(a->map.map_h + 1, a->map.final);
	free(a->mlx);
	free(a);
}
