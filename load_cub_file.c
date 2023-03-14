/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:17:43 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:46:04 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_cub_file(t_all *a, char *filename)
{
	int		fd;

	fd = 0;
	malloc_tex(a);
	open_file(a, filename, &fd);
	read_file(a, fd);
	make_map_final(a);
	init_dir(a);
}

void	open_file(t_all *a, char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		print_error(a, "from open_file: wrong file");
}

void	read_file(t_all *a, int fd)
{
	int		ret_gnl;
	char	*line;

	ret_gnl = 1;
	while (ret_gnl == 1)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
		{
			free(line);
			print_error(a, "from read_file: wrong get_next_line");
		}
		check_line_info(a, line);
		free(line);
	}
}

void	load_texture_image(t_all *a, char *line, char **double_ptr)
{
	a->img.img = mlx_xpm_file_to_image(a->mlx, double_ptr[1],
					&a->img.img_w, &a->img.img_h);
	if (a->img.img == NULL)
	{
		free_char_arrays(ft_word_num(line, ' ') + 1, double_ptr);
		free(line);
		print_error(a, "from load_texture_image: wrong wall texture");
	}
	a->img.data = (int *)mlx_get_data_addr(a->img.img,
					&a->img.bpp, &a->img.size_l, &a->img.eda);
	save_texture_image(a);
	mlx_destroy_image(a->mlx, a->img.img);
}
