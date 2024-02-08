/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:58:23 by sade              #+#    #+#             */
/*   Updated: 2023/11/14 14:01:13 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	chr;

	ptr = (unsigned char *)str;
	chr = (unsigned char)c;
	while (len > 0)
	{
		*ptr = chr;
		++ptr;
		--len;
	}
	return (str);
}
