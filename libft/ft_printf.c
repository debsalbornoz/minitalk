/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:39:41 by dlamark-          #+#    #+#             */
/*   Updated: 2023/09/30 14:19:53 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			len += print_format(args, *(str + 1));
			str++;
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	len = len + i;
	va_end(args);
	return (len);
}

int	print_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	if ((format == 'i') || (format == 'd'))
		len += ft_putnbr(va_arg(args, int));
	if (format == '%')
	{
		ft_putchar('%');
		len += 1;
	}
	if (format == 'x')
		len += ft_hexadecimal(va_arg(args, unsigned int), HEX_BASE_LOWER, 16);
	if (format == 'X')
		len += ft_hexadecimal(va_arg(args, unsigned int), HEX_BASE_UPPER, 16);
	if (format == 'p')
		len += ft_putptr(va_arg(args, long long int), HEX_BASE_LOWER, 16);
	if (format == 'u')
		len += ft_unsigned(va_arg(args, unsigned long int));
	return (len);
}
