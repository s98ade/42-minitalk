/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:04 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:46 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	int			count;
	const char	*base;
	int			error;

	base = "0123456789";
	count = 0;
	if (n >= 10)
		count = ft_print_unsigned (n / 10);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 10], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}
