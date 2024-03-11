/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:22:30 by sade              #+#    #+#             */
/*   Updated: 2023/11/12 13:28:29 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	else if (result)
	{
		ft_strlcpy(result, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (result);
}
