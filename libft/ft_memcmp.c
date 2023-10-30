/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:29:30 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:11:22 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((unsigned char)n > 0)
	{
		if (*m1 != *m2)
		{
			return ((int)*m1 - (int)*m2);
		}
		m1++;
		m2++;
		n--;
	}
	return (0);
}
