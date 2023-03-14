/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:49:10 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/14 10:52:20 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr_ptr(const char *s, int c)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (42)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
}
