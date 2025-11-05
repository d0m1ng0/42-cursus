/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:32:05 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 11:47:23 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_to_buf.h"

#define BUF_SIZ 4096
/*
	return the size in bytes of file at (path)
*/
static size_t	file_size(const char *path)
{
	int		fd;
	char	buf[BUF_SIZ];
	int		siz;
	ssize_t	cnt;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	siz = 0;
	cnt = read(fd, buf, BUF_SIZ);
	while (cnt > 0)
	{
		siz += cnt;
		cnt = read(fd, buf, BUF_SIZ);
	}
	close(fd);
	return (siz);
}

/*
	read file at (path) into malloc'ed char buffer
	ATTN : caller is responsible for free-ing
	returned pointer
*/
char	*file_to_buf(const char *path)
{
	int		fd;
	ssize_t	siz;
	ssize_t	chk;
	char	*buf;

	siz = file_size(path);
	if (siz == 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = (char *) malloc((siz + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	chk = 0;
	while (chk < siz)
		chk += read(fd, buf, siz - chk + 1);
	buf[chk] = '\0';
	close(fd);
	return (buf);
}
