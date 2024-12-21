/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:53:32 by anaamaja          #+#    #+#             */
/*   Updated: 2024/12/12 13:05:25 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	i;
	size_t	total;
	size_t	j;

	// if (!s1 && !s2)
	// 	return (NULL);
	// if (!s1)
	// 	return (ft_strdup(s2));
	// if (!s2)
	// 	return (ft_strdup(s1));
	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (total + 1));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[total] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	//size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	//s_len = ft_strlen(s);
	// if (start >= s_len)
	// {
	// 	str = malloc(1);
	// 	if (!str)
	// 		return (NULL);
	// 	str[0] = '\0';
	// 	return (str);
	// }
	// if (len > s_len - start)
	// 	len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int search_str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == search_str)
			return ((char *)str + i);
		i++;
	}
	if (search_str == '\0')
		return ((char *)str + i);
	return (NULL);
}

