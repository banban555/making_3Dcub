/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:10:01 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 18:30:27 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_char_arrays(int len, char **arrays)
{
	int j;

	j = 0;
	while (j < len)
	{
		free(arrays[j]);
		arrays[j] = NULL;
		++j;
	}
	free(arrays);
	arrays = NULL;
}

void	free_int_arrays(int len, int **arrays)
{
	int j;

	j = 0;
	while (j < len)
	{
		free(arrays[j]);
		arrays[j] = NULL;
		++j;
	}
	free(arrays);
	arrays = NULL;
}
