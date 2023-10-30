/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:00:02 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/20 16:19:57 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (psrc < pdest)
	{
		while (n > 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else
	{
		ft_memcpy(pdest, psrc, n);
	}
	return (dest);
}
