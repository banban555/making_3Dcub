/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:11:23 by hayelee           #+#    #+#             */
/*   Updated: 2021/02/12 20:50:37 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numb_len(int n)
{
	int cnt;

	if (n == -2147483648)
		cnt = 11;
	else if (n < 0 && n > -2147483648)
	{
		n = n * (-1);
		cnt = 2;
		while (n / 10 != 0)
		{
			cnt++;
			n = n / 10;
		}
	}
	else
	{
		cnt = 1;
		while (n / 10 != 0)
		{
			cnt++;
			n = n / 10;
		}
	}
	return (cnt);
}

static char	*ft_min_str(int n, int len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[len - 1] = '8';
	len = len - 1;
	n = 214748364;
	while (len-- > 1)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_neg_str(int n, int len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	n = n * (-1);
	str[len] = '\0';
	while (len-- > 1)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_pos_str(int n, int len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_numb_len(n);
	if (n == -2147483648)
		str = ft_min_str(n, len);
	else if (n < 0 && n > -2147483648)
		str = ft_neg_str(n, len);
	else if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str[0] = n + '0';
		str[1] = '\0';
	}
	else
		str = ft_pos_str(n, len);
	return (str);
}
