/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:17:36 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 14:53:36 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *stash)
{
	int		i;
	char	*cleaned_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	cleaned_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (cleaned_stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		l;

	l = 0;
	if (!stash || !stash[l])
		return (NULL);
	while (stash[l] && stash[l] != SEPARATOR)
		l++;
	if (stash[l] == SEPARATOR)
		l++;
	line = (char *)malloc(l + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, l + 1);
	return (line);
}

static char	*ft_create_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	package_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	package_read = 1;
	while (package_read > 0 && (!stash || !ft_strchr(stash, SEPARATOR)))
	{
		package_read = read(fd, buffer, BUFFER_SIZE);
		if (package_read == -1)
			return (free(buffer), free(stash), NULL);
		if (package_read > 0)
		{
			buffer[package_read] = '\0';
			stash = ft_strjoin_stash_buffer(stash, buffer);
			if (!stash)
				return (free(buffer), NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_create_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_clean_stash(stash);
	return (line);
}
