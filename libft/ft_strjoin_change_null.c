/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_change_null.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:49:55 by hayelee           #+#    #+#             */
/*   Updated: 2021/06/17 15:59:27 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_change_null(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (s1 == 0)
		return (ft_strdup(s2));
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2))))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	if (s1[i] == '\0')
		str[i] = 'a';
	j = -1;
	while (s2[++j])
		str[i + 1 + j] = s2[j];
	str[i + 1 + j] = '\0';
	return (str);
}
