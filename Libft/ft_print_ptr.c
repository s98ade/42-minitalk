/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:14:26 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:38 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long ptr)
{
	int	count;
	int	add;

	count = 0;
	add = write (1, "0x", 2);
	if (add == -1)
		return (-1);
	count = (add + ft_print_hex_lower (ptr));
	if (count == -1)
		return (-1);
	return (count);
}
