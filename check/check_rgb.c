/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:19:05 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:56:19 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb_by_comma(t_all *a, char *line)
{
	char	**double_ptr;
	char	opt;

	opt = line[0];
	if (line[0] == 'F')
		++a->opt.f;
	if (line[0] == 'C')
		++a->opt.c;
	if (a->opt.f >= 2 || a->opt.c >= 2 || check_input_in_rgb(a, line) != 2)
	{
		free(line);
		print_error(a, "from check_rgb_by_comma: wrong RGB");
	}
	double_ptr = ft_split((line + 1), ',');
	if (double_ptr == NULL)
	{
		free(line);
		print_error(a, "from check_rgb_by_comma: wrong malloc");
	}
	check_number_of_split_line(a, line, double_ptr);
	check_rgb_by_space(a, line, double_ptr, opt);
	free_char_arrays(ft_word_num(line, ',') + 1, double_ptr);
}

void	check_rgb_by_space(t_all *a, char *line, char **ptr, char opt)
{
	int nmb_ptr[3];
	int i;

	i = -1;
	while (++i < 3)
	{
		if (ft_word_num(ptr[i], ' ') != 1)
		{
			free_char_arrays(ft_word_num(line, ',') + 1, ptr);
			free(line);
			print_error(a, "from check_rgb_by_space: wrong RGB");
		}
		else
		{
			nmb_ptr[i] = ft_atoi(ptr[i]);
			if (nmb_ptr[i] > 255 || nmb_ptr[i] < 0)
			{
				free_char_arrays(ft_word_num(line, ',') + 1, ptr);
				free(line);
				print_error(a, "from check_rgb_by_space: wrong RGB");
			}
		}
	}
	save_rgb(a, nmb_ptr, opt);
}

int		check_input_in_rgb(t_all *a, char *line)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (line[++i])
	{
		if (ft_strchr_idx(" ,0123456789", line[i]) < 0)
		{
			free(line);
			print_error(a, "from check_input_in_rgb: wrong RGB");
		}
		else
		{
			if (line[i] == ',')
				++cnt;
		}
	}
	return (cnt);
}

void	check_number_of_split_line(t_all *a, char *line, char **ptr)
{
	if (ft_word_num(line, ',') != 3)
	{
		free_char_arrays(ft_word_num(line, ',') + 1, ptr);
		free(line);
		print_error(a, "from check_number_of_split_line: wrong RGB");
	}
}
