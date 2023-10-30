/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:26:57 by dlamark-          #+#    #+#             */
/*   Updated: 2023/08/08 17:17:23 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_unsigned(unsigned int nbr)
{
	unsigned int	i;

	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	write(1, &c, 1);
	return (count_unsigned(n));
}
