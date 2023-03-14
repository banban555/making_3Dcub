/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:09:36 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/13 09:41:24 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr_ptr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = 0;
	while (42)
	{
		if (*s == (unsigned char)c)
			ptr = (unsigned char *)s;
		if (*s == '\0')
			return ((char *)ptr);
		s++;
	}
}
