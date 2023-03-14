/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:54:05 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/25 17:21:54 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_idx(const char *s, char c)
{
	int idx;
	int ret_idx;

	idx = 0;
	ret_idx = -1;
	while (42)
	{
		if (s[idx] == (unsigned char)c)
			ret_idx = idx;
		if (s[idx] == '\0')
			return (ret_idx);
		idx++;
	}
}
