/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:27:30 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 18:26:52 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_rgb(t_all *a, int nmb_ptr[], char opt)
{
	if (opt == 'F')
		a->opt.color_f = (nmb_ptr[0] << 16) + (nmb_ptr[1] << 8) + nmb_ptr[2];
	if (opt == 'C')
		a->opt.color_c = (nmb_ptr[0] << 16) + (nmb_ptr[1] << 8) + nmb_ptr[2];
}

int		save_idx_tex(t_all *a, char *line)
{
	a->idx_tex = -1;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		++a->opt.no;
		a->idx_tex = N;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		++a->opt.ea;
		a->idx_tex = E;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		++a->opt.we;
		a->idx_tex = W;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		++a->opt.so;
		a->idx_tex = S;
	}
	return (a->idx_tex);
}

void	save_texture_image(t_all *a)
{
	int x;
	int y;

	y = -1;
	while (++y < a->img.img_h)
	{
		x = -1;
		while (++x < a->img.img_w)
		{
			a->tex[a->idx_tex][a->img.img_w * y + x] =
			a->img.data[a->img.img_w * y + x];
		}
	}
}
