/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:47:11 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:44 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, (int)s1[start]))
	{
		start++;
	}
	while (ft_strchr(set, (int)s1[end - 1]))
	{
		end--;
	}
	return (ft_substr(s1, start, end - start));
}
