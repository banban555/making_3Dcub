/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:46:08 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:42:54 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "key/key_macos.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <math.h>
# include <stdio.h>

# define WIDTH					1000
# define HEIGHT					800

# define N						0
# define E						1
# define W						2
# define S						3

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

typedef struct	s_key
{
	double	m_speed;
	double	r_speed;
	int		k_w;
	int		k_a;
	int		k_s;
	int		k_d;
	int		k_right;
	int		k_left;
	int		k_esc;
}				t_key;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		eda;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct	s_opt
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		color_f;
	int		color_c;
	int		full;
}				t_opt;

typedef struct	s_map
{
	char	dir_p;
	int		num_p;
	int		map_w;
	int		map_h;
	char	*draft;
	char	**final;
	char	**copy;
}				t_map;

typedef struct	s_cal
{
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	double	pwdist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		d_start;
	int		d_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_p;
	int		tex_y;
}				t_cal;

typedef struct	s_all
{
	char	*extension;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		**tex;
	int		idx_tex;
	void	*mlx;
	void	*win;
	int		map_part;
	t_key	key;
	t_img	img;
	t_opt	opt;
	t_map	map;
	t_cal	cal;
}				t_all;

/*
**cub3d.c
*/
void			run_mlx(t_all *a);

/*
**draw.c
*/
void			draw(t_all *a);

/*
**main_loop.c
*/
int				main_loop(t_all *a);
void			set_background(t_all *a);
void			calc_wall(t_all *a);
void			put_color_to_image(t_all *a);

/*
**load_cub_file.c
*/
void			load_cub_file(t_all *a, char *filename);
void			open_file(t_all *a, char *filename, int *fd);
void			read_file(t_all *a, int fd);
void			load_texture_image(t_all *a, char *line, char **double_ptr);

/*
**check_line_info.c
*/
void			check_line_info(t_all *a, char *line);
void			check_line_full_option(t_all *a);
void			check_wrong_line_input(t_all *a, char *line);

/*
**make_map.c
*/
void			make_map_draft(t_all *a, char *line);
void			make_map_final(t_all *a);

/*
**free_array.c
*/
void			free_char_arrays(int len, char **arrays);
void			free_int_arrays(int len, int **arrays);

/*
**malloc_array.c
*/
void			malloc_tex(t_all *a);
void			malloc_map_draft(t_all *a);
void			malloc_map_final(t_all *a);
void			malloc_map_copy(t_all *a);

/*
**check_map.c
*/
void			check_map(t_all *a, char *line);
void			check_map_final(t_all *a);

/*
**check_argv.c
*/
void			check_argv(t_all *a, int argc, char *argv[]);

/*
**check_extension.c
*/

int				check_extension(t_all *a, char *s);

/*
**check_path.c
*/
void			check_wall_path(t_all *a, char *line);
void			check_wrong_identifier(t_all *a, char *line);
void			check_texture_path(t_all *a, char *line);
void			check_number_of_space(t_all *a, char *line);
void			check_number_of_news(t_all *a, char *line);

/*
**check_rgb.c
*/
void			check_rgb_by_comma(t_all *a, char *line);
void			check_rgb_by_space(t_all *a, char *line, char **ptr, char opt);
int				check_input_in_rgb(t_all *a, char *line);
void			check_number_of_split_line(t_all *a, char *line, char **ptr);

/*
**check_position.c
*/
void			check_player_position(t_all *a);

/*
**check_map_validity.c
*/
void			check_map_copy(t_all *a);
void			check_by_dfs(t_all *a, int x, int y);
int				set_a(int i, int x);
int				set_b(int i, int y);
void			error_or_dfs(t_all *a, int j, int k);

/*
**save_option.c
*/
void			save_rgb(t_all *a, int nmb_ptr[], char opt);
int				save_idx_tex(t_all *a, char *line);
void			save_texture_image(t_all *a);

/*
**save_map_final.c
*/
void			save_map_final(t_all *a, char **map_second);

/*
**calc_by_hit_value.c
*/
void			when_hit_is_zero(t_all *a);
void			when_hit_is_one(t_all *a, int x);

/*
**set.c
*/
void			set_data_for_calc(t_all *a, int x);
void			set_step_and_sidedist(t_all *a);
void			set_data_for_pick_1(t_all *a);
void			set_data_for_pick_2(t_all *a);
void			set_texture_idx(t_all *a);

/*
**init_info.c
*/
void			init_info(t_all *a);

/*
**init_dir.c
*/
void			init_dir(t_all *a);
void			init_dir_ns(t_all *a);
void			init_dir_we(t_all *a);

/*
**print_error.c
*/
void			print_error(t_all *a, char *message);
void			free_all(t_all *a);

/*
**key_setting.c
*/
int				key_press(int key, t_all *a);
int				key_release(int key, t_all *a);
int				key_exit(t_all *a);
void			key_update(t_all *a);

/*
**key_move.c
*/
void			set_abcd(t_all *a, double num[]);
void			key_ws(t_all *a, double num[]);
void			key_ad(t_all *a, double num[]);

/*
**key_rotate.c
*/
void			key_rotate(t_all *a);
void			key_right(t_all *a, double old_dir_x, double old_plane_x);
void			key_left(t_all *a, double old_dir_x, double old_plane_x);

#endif
