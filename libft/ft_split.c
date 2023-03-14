/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:11:36 by hayelee           #+#    #+#             */
/*   Updated: 2021/05/14 10:51:17 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **array, size_t i)
{
	while (i--)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
	return (NULL);
}

static char	*ft_make_word(char *word, char const *s, int k, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
		word[i++] = s[k - word_len--];
	word[i] = '\0';
	return (word);
}

static char	**ft_do_split(char **array, char const *s, char c, int word_num)
{
	int		i;
	int		k;
	int		word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		if (!(array[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (ft_freeall(array, i));
		ft_make_word(array[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}

char		**ft_split(char const *s, char c)
{
	int		word_num;
	char	**array;

	if (s == 0)
		return (NULL);
	word_num = ft_word_num(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (word_num + 1))))
		return (NULL);
	ft_do_split(array, s, c, word_num);
	return (array);
}
