/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:25:47 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:13 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((char)c == '\0')
	{
		return ((char *)s + len_s);
	}
	while (len_s > 0 && *(s + (len_s - 1)) != (char)c)
	{
		len_s--;
	}
	if (len_s > 0 && *(s + (len_s - 1)) == (char)c)
		return ((char *)s + (len_s - 1));
	else
		return (NULL);
}
