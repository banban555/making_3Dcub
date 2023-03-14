/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:38:59 by hayelee           #+#    #+#             */
/*   Updated: 2021/02/10 16:32:30 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			symbol;
	long long	numb;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	symbol = 1;
	if (nptr[i] == '-')
		symbol = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	numb = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (symbol * numb > 2147483647)
			return (-1);
		else if (symbol * numb < -2147483648)
			return (0);
		else
			numb = (numb * 10) + (nptr[i] - 48);
		i++;
	}
	return (symbol * numb);
}
