/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:22:33 by dlamark-          #+#    #+#             */
/*   Updated: 2023/05/28 16:03:36 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long int nbr)
{
	unsigned int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digits;
	long int	num;

	num = n;
	digits = count(n);
	if (n < 0)
	{
		num = num * -1;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	*(str + digits) = '\0';
	while (digits--)
	{
		*(str + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
