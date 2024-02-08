/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:59:54 by sade              #+#    #+#             */
/*   Updated: 2023/11/13 11:31:34 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long ln)
{
	int	count;

	count = 0;
	if (ln <= 0)
		count = 1;
	while (ln != 0)
	{
		ln /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	digit;
	int		len;

	len = ft_numlen(n);
	digit = n;
	if (n < 0)
		digit *= -1;
	result = (char *)malloc(sizeof(char) * (len +1));
	if (result == NULL)
		return (NULL);
	result[len] = 0;
	if (digit == 0)
		result[0] = '0';
	else
	{
		while (--len, digit != 0)
		{
			result[len] = ((digit % 10) + '0');
			digit = (digit - (digit % 10)) / 10;
		}
		if (n < 0)
			result[digit] = '-';
	}
	return (result);
}
