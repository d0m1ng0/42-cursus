/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:03:14 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/17 19:41:23 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_create_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}
/*
#include "get_next_line_bonus.h"

int	main(void)
{
	int fd1;
	int fd2;
	char	*line;

	fd1 = open("file1", O_RONLY);
	fd2 = open("file2", O_RONLY);	
	if (fd1 == -1 || fd2 == -1)
	{
		ft_putstr_fd("Error in file opening", 1);
		return (1);
	}
	//Lines 1
	line = get_next_line(fd1);
	ft_putstr_fd("File 1, Line 1:\n", 1);
	ft_putstr_fd(line, 1);
	free(line);
	line = get_next_line(fd2);
	ft_putstr_fd("File 2, Line 1:\n", 1);
	ft_putstr_fd(line, 1);
	free(line);
	//Lines 2
	line = get_next_line(fd1);
	ft_putstr_fd("File 1, Line 2:\n", 1);
	ft_putstr_fd(line, 1);
	free(line);
	line = get_next_line(fd2);
	ft_putstr_fd("File 2, Line 2:\n", 1);
	ft_putstr_fd(line, 1);
	free(line);

	close(fd1);
	close(fd2);
	return(0);
}
*/
