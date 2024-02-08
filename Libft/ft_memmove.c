/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:24:36 by sade              #+#    #+#             */
/*   Updated: 2023/11/14 13:23:54 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	if (dst - src > 0 && dst - src >= (long) len)
		return (ft_memcpy(dst, src, len));
	if (src - dst > 0)
		return (ft_memcpy(dst, src, len));
	while (len > 0 && !(dst == NULL || src == NULL))
	{
		len--;
		p_dst[len] = p_src[len];
	}
	return (dst);
}
