/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:06:29 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/23 14:44:03 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_extension(t_all *a, char *s)
{
	char *ptr;

	ptr = ft_strrchr_ptr(s, '.');
	if (!ptr)
		return (-1);
	if (ft_strncmp_extension((ptr + 1), a->extension, 4) != 0)
		return (-1);
	return (0);
}
