/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:51 by anaamaja          #+#    #+#             */
/*   Updated: 2024/12/12 13:04:48 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_to_remainder(char *remainder, char *buffer)
{
	char	*temp;

	if (!remainder)
		remainder = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
	}
	return (remainder);
}

int	has_newline(char *str)
{
	return (ft_strchr(str, '\n') != NULL);
}

char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	newline_pos = ft_strchr(*remainder, '\n');
	line = ft_substr(*remainder, 0, (newline_pos - *remainder + 1));
	temp = ft_strdup(newline_pos + 1);
	free(*remainder);
	*remainder = temp;
	return (line);
}

char	*finalize_remainder(char **remainder)
{
	char	*line;

	if (*remainder)
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remainder;
	size_t		bytes_read;

	remainder = NULL;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, (BUFFER_SIZE - 1));
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = append_to_remainder(remainder, buffer);
		if (has_newline(remainder))
			return (extract_line(&remainder));
	}
	free(buffer);
	return (finalize_remainder(&remainder));
}
