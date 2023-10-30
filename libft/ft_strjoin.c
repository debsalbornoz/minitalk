/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:13:22 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:24:55 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s3_len;
	char	*s3;
	char	*str1;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc((s3_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, str1, s3_len + 1);
	ft_strlcat(s3, s2, s3_len + 1);
	return (s3);
}
