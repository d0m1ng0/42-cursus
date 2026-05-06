/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:25:04 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 08:35:49 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_close_all(int fd_in, int fd_out, int fd_pipe[2])
{
	if (fd_in >= 0)
		close(fd_in);
	if (fd_out >= 0)
		close(fd_out);
	if (fd_pipe[0] >= 0)
	{
		close(fd_pipe[0]);
		fd_pipe[0] = -1;
	}
	if (fd_pipe[1] >= 0)
	{
		close(fd_pipe[1]);
		fd_pipe[1] = -1;
	}
}

void	px_close_fd(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

void	px_close_fd_except(int *fd, int except)
{
	if (*fd >= 0 && *fd != except)
	{
		close(*fd);
		*fd = -1;
	}
}

void	px_close_after_child1(int *fd_in, int fd_pipe[2])
{
	if (fd_pipe[1] >= 0)
	{
		close(fd_pipe[1]);
		fd_pipe[1] = -1;
	}
	if (*fd_in >= 0)
	{
		close(*fd_in);
		*fd_in = -1;
	}
}
