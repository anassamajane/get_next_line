/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:51 by anaamaja          #+#    #+#             */
/*   Updated: 2024/12/15 17:25:28 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*read_and_store(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (remainder && ft_strchr(remainder, '\n'))
		return (remainder);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(remainder, buffer);
			free(remainder);
			remainder = temp;
		}
		if (ft_strchr(remainder, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (remainder);
}

char	*extract_line(char *remainder)
{
	char	*line;
	char	*newline_pos;

	if (!remainder)
		return (NULL);

	newline_pos = ft_strchr(remainder, '\n');
	if (newline_pos)
		line = ft_substr(remainder, 0, (newline_pos - remainder + 1));
	else
		line = ft_strdup(remainder);

	return (line);
}

char	*update_remainder(char *remainder)
{
	char	*newline_pos;
	char	*new_remainder;

	if (!remainder)
		return (NULL);

	newline_pos = ft_strchr(remainder, '\n');
	new_remainder = NULL;
	if (newline_pos)
	{
		if (*(newline_pos + 1))
			new_remainder = ft_strdup(newline_pos + 1);
		free(remainder);
		return (new_remainder);
	}
	free(remainder);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);

	remainder = read_and_store(fd, remainder);
	if (!remainder)
		return (NULL);

	line = extract_line(remainder);
	remainder = update_remainder(remainder);

	return (line);
}
