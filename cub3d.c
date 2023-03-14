/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:43:37 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:19:33 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_all *a;

	a = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!a)
		print_error(a, "from main: wrong malloc");
	a->mlx = mlx_init();
	init_info(a);
	check_argv(a, argc, argv);
	load_cub_file(a, argv[1]);
	run_mlx(a);
	return (0);
}

void	run_mlx(t_all *a)
{
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "cub3D");
	a->img.img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->img.data = (int *)mlx_get_data_addr(a->img.img, &a->img.bpp,
	&a->img.size_l, &a->img.eda);
	mlx_loop_hook(a->mlx, &main_loop, a);
	mlx_hook(a->win, X_EVENT_KEY_PRESS, 0, &key_press, a);
	mlx_hook(a->win, X_EVENT_KEY_RELEASE, 0, &key_release, a);
	mlx_hook(a->win, X_EVENT_KEY_EXIT, 0, &key_exit, a);
	mlx_loop(a->mlx);
}
