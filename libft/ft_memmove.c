/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:39:27 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/14 14:10:06 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = -1;
	if (dst == 0 && src == 0)
		return (NULL);
	if (str1 > str2)
	{
		while ((int)(--len) >= 0)
			str1[len] = str2[len];
	}
	else
	{
		while (++i < len)
			str1[i] = str2[i];
	}
	return (dst);
}
