/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:19:09 by sade              #+#    #+#             */
/*   Updated: 2024/01/14 15:52:00 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			++count;
			i = 1;
		}
		++s;
	}
	return (count);
}

static int	ft_substrlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		++i;
	}
	return (i);
}

static char	*new_string(const char *s, char c)
{
	char	*new_str;
	int		size_str;

	size_str = ft_substrlen(s, c);
	new_str = (char *)malloc((size_str + 1) * (sizeof(char)));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, size_str + 1);
	return (new_str);
}

char	**free_all(char **result, int num)
{
	if (result != NULL)
	{
		while (num > 0)
			free (result[--num]);
		free(result);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_str;
	int		count_pos;

	num_str = count_words(s, c);
	result = (char **)malloc((num_str + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	count_pos = 0;
	while (count_pos < num_str)
	{
		if (*s == c)
			++s;
		else
		{
			result[count_pos] = new_string(s, c);
			if (result[count_pos] == NULL)
				return (free_all(result, count_pos));
			s += ft_strlen(result[count_pos]);
			++count_pos;
		}
	}
	result[num_str] = NULL;
	return (result);
}
