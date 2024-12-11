/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:51 by anaamaja          #+#    #+#             */
/*   Updated: 2024/12/11 20:10:15 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	char buffer[1024];
	static char	*remainder = NULL;
	char	*line;
	char	*temp;
	char	*newline_pos;
	int	bytes_read;

	while ((bytes_read = read(fd, buffer, sizeof(buffer - 1))) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!remainder)
		{
			remainder = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(remainder, buffer);
			free(remainder);
			remainder = temp;
		}
		newline_pos = ft_strchr(remainder, '\n');
		if (newline_pos)
		{
			line = ft_substr(remainder, 0, (newline_pos - remainder + 1));
			temp = ft_strdup(newline_pos + 1);
			free (remainder);
			remainder = temp;
			return (line);
		}
	}
	if (remainder)
	{
		line = ft_strdup(remainder);
		free (remainder);
		remainder = NULL;
		return (line);
	}
	return (NULL);
}

#include <stdio.h>

int	main()
{
	int	fd = open ("text.txt", O_RDONLY);
	if (fd < 0)
	{
    	perror("Error opening file");
    	return (1);
	}


	char	*line = get_next_line(fd);
	char	*line2 = get_next_line(fd);
	char	*line3 = get_next_line(fd);
	printf("line 1:%s\n", line);
	printf("line 2:%s\n", line2);
	printf("line 3:%s\n", line3);
}
