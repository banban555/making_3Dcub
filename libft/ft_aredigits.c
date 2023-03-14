/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aredigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:27:49 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/25 17:18:31 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_aredigits(char *s)
{
	int i;

	i = 0;
	while (ft_isdigit(s[i]) > 0)
		++i;
	if (s[i] != '\0')
		return (-1);
	return (0);
}