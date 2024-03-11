/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:25:31 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:59:25 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_digit(int n)
{
	int			count;
	const char	*base;
	int			error;

	base = "0123456789";
	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		if (ft_print_chr('-') == -1)
			return (-1);
		count++;
		n = -1 * n;
	}
	if (n >= 10)
		count += ft_print_digit(n / 10);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 10], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}
