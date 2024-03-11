/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:00:32 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:31 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_upper(unsigned int n)
{
	int			count;
	const char	*base;
	int			error;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count = ft_print_hex_upper(n / 16);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 16], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}
