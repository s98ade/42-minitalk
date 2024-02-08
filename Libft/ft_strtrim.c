/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:45:08 by sade              #+#    #+#             */
/*   Updated: 2024/02/08 20:34:03 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	trimmed_len;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]))
		++start;
	while (end > 0 && ft_strchr(set, s1[end]))
		--end;
	trimmed_len = end - start + 1;
	trimmed = ft_substr(s1 + start, 0, trimmed_len);
	return (trimmed);
}
