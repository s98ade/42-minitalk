/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:19:33 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:42 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	i;
	int	error;

	i = 0;
	if (str == NULL)
	{
		error = write (1, "(null)", 6);
		if (error == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		error = write (1, &str[i], 1);
		if (error == -1)
			return (-1);
		++i;
	}
	return (i);
}
