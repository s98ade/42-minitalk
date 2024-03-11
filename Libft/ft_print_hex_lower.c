/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:02:39 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:28 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_lower(unsigned long n)
{
	int			count;
	const char	*base;
	int			error;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count = ft_print_hex_lower(n / 16);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 16], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}
