/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:44:28 by sade              #+#    #+#             */
/*   Updated: 2024/01/29 14:16:55 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long	number;
	int		negativ;

	number = 0;
	negativ = 1;
	while (*str && *str == '-' && *str == ' ' && (*str >= 9 || *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negativ *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * negativ);
}
