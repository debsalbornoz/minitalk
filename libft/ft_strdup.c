/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:23:14 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:44:05 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*duplicate;
	int		i;

	len = ft_strlen(s) + 1;
	duplicate = (char *)malloc(len * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	*duplicate = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
