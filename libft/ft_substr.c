/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:13:48 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:31:03 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
	{
		substr = malloc((s_len - start + 1) * sizeof(char));
		len = s_len - start;
	}
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
