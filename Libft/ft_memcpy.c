/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:16:35 by sade              #+#    #+#             */
/*   Updated: 2023/11/07 13:46:08 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	const char	*p_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	p_dst = (char *)dst;
	p_src = (const char *)src;
	while (len > 0)
	{
		*p_dst = *p_src;
		++p_dst;
		++p_src;
		--len;
	}
	return (dst);
	if (!src && !dst)
	{
		return (NULL);
	}
}
