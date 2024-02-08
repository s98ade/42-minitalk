/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:45:38 by sade              #+#    #+#             */
/*   Updated: 2023/11/13 12:48:37 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	chr;
	char	*ptr;

	chr = (char)c;
	ptr = (char *)str;
	while (*ptr != '\0')
		ptr++;
	while (ptr >= str)
	{
		if (*ptr == chr)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
