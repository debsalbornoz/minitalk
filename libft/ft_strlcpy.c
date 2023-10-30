/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:29:12 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:28:05 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	else if (size == 0)
		return (src_len);
	while (i < size - 1 && *src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}
