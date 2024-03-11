/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:20:59 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 09:57:51 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<fcntl.h>
#include<stdio.h>

char	*ft_extract_line(char **result)
{
	char	*remainder;
	char	*extr_line;

	remainder = *result;
	while (*remainder != '\0' && *remainder != '\n')
		++remainder;
	if (*remainder == '\n')
		++remainder;
	extr_line = gnl_substr(*result, 0, (size_t)(remainder - *result));
	if (!extr_line)
	{
		free (*result);
		*result = NULL;
		return (NULL);
	}
	remainder = gnl_substr(remainder, 0, gnl_strlen(remainder));
	free(*result);
	*result = remainder;
	return (extr_line);
}

char	*ft_combine_line(char *result, char *buffer, int fd)
{
	ssize_t	line_bytes;

	line_bytes = 1;
	while (!(gnl_strchr(result, '\n')) && line_bytes != 0)
	{
		line_bytes = read(fd, buffer, BUFFER_SIZE);
		if (line_bytes == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[line_bytes] = '\0';
		result = gnl_strjoin(result, buffer);
		if (!result)
		{
			free (buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (result);
}

char	*ft_read_upd8(char *result, char *buffer, int fd)
{
	result = ft_combine_line(result, buffer, fd);
	if (!result)
	{
		result = NULL;
		return (NULL);
	}
	if (!*result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!result)
		result = gnl_strdup("");
	if (!result)
		return (NULL);
	buffer = malloc((1 + BUFFER_SIZE) * sizeof(*buffer));
	if (!buffer)
	{
		free (result);
		result = NULL;
		return (NULL);
	}
	result = ft_read_upd8(result, buffer, fd);
	if (!result)
		return (NULL);
	return (ft_extract_line(&result));
}
int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	
	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	for (i = 0; i < 6; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free (line);
	return (0);
}