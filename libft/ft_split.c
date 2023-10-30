/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:22:22 by dlamark-          #+#    #+#             */
/*   Updated: 2023/10/12 13:21:22 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (*s != c && *s != '\0')
		count++;
	while (*s != '\0')
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	i;
	size_t	j;

	strings = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	j = 0;
	if (strings == NULL)
		return (NULL);
	while (*s && count_words(s, c) != 0)
	{
		while (*s == c && *s)
			s++;
		i = 0;
		if (*s == '\0' && *(s - 1) == c)
			break ;
		while (*s != c && *s)
		{
			s++;
			i++;
		}
		strings[j++] = ft_substr(s - i, 0, i);
	}
	strings[j] = NULL;
	return (strings);
}
