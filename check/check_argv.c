/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:16:14 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:43:04 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_argv(t_all *a, int argc, char *argv[])
{
	if (argc == 1 || argc >= 3)
		print_error(a, "from check_argv: wrong argv");
	else if (argc == 2)
	{
		a->extension = "cub";
		if (check_extension(a, argv[1]) < 0)
			print_error(a, "from check_argv: wrong argv");
	}
}
