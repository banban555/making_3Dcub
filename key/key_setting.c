/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:32:00 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 17:01:56 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_all *a)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(a->mlx, a->img.img);
		mlx_destroy_window(a->mlx, a->win);
		free_all(a);
		exit(0);
	}
	else if (key == K_W)
		a->key.k_w = 1;
	else if (key == K_A)
		a->key.k_a = 1;
	else if (key == K_S)
		a->key.k_s = 1;
	else if (key == K_D)
		a->key.k_d = 1;
	else if (key == K_AR_L)
		a->key.k_left = 1;
	else if (key == K_AR_R)
		a->key.k_right = 1;
	return (0);
}

int		key_release(int key, t_all *a)
{
	if (key == K_W)
		a->key.k_w = 0;
	else if (key == K_A)
		a->key.k_a = 0;
	else if (key == K_S)
		a->key.k_s = 0;
	else if (key == K_D)
		a->key.k_d = 0;
	else if (key == K_AR_L)
		a->key.k_left = 0;
	else if (key == K_AR_R)
		a->key.k_right = 0;
	return (0);
}

int		key_exit(t_all *a)
{
	mlx_destroy_image(a->mlx, a->img.img);
	mlx_destroy_window(a->mlx, a->win);
	free_all(a);
	exit(0);
	return (0);
}

void	key_update(t_all *a)
{
	double num[4];

	set_abcd(a, num);
	key_ws(a, num);
	key_ad(a, num);
	key_rotate(a);
}
