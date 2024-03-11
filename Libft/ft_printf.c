/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:01:07 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:49 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_chr(va_arg(args, int));
	else if (format == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_print_digit(va_arg(args, int));
	else if (format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		count += ft_print_percent();
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += check_format(args, *(++format));
		else
			count += write (1, format, 1);
		++format;
		if (count == -1)
			return (-1);
	}
	va_end(args);
	return (count);
}
