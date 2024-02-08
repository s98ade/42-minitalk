/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:45 by sade              #+#    #+#             */
/*   Updated: 2023/11/10 14:24:17 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*p_str;

	p_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p_str[i] == (unsigned char)c)
		{
			return ((void *)(p_str + i));
		}
		++i;
	}
	return (NULL);
}
