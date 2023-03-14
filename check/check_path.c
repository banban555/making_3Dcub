/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:18:12 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:43:10 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_path(t_all *a, char *line)
{
	if (save_idx_tex(a, line) < 0)
	{
		free(line);
		print_error(a, "from check_wall_path: wrong wall texture");
	}
	check_texture_path(a, line);
}

void	check_texture_path(t_all *a, char *line)
{
	char	**double_ptr;

	a->extension = "xpm";
	check_number_of_news(a, line);
	double_ptr = ft_split(line, ' ');
	if (!double_ptr)
		print_error(a, "from check_texture_path: wrong malloc");
	else if (check_extension(a, double_ptr[1]) < 0)
	{
		free_char_arrays(ft_word_num(line, ' ') + 1, double_ptr);
		free(line);
		print_error(a, "from check_texture_path: wrong extension");
	}
	load_texture_image(a, line, double_ptr);
	free_char_arrays(ft_word_num(line, ' ') + 1, double_ptr);
}

void	check_number_of_news(t_all *a, char *line)
{
	if (a->opt.no > 1 || a->opt.ea > 1 || a->opt.we > 1 || a->opt.so > 1)
	{
		free(line);
		print_error(a, "from check_number_of_news: wrong wall texture");
	}
}
