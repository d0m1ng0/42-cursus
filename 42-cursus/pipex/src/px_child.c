/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:55:56 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 08:01:01 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_setup_input_null(void)
{
	int	dev_null;

	dev_null = open("/dev/null", O_RDONLY);
	if (dev_null == -1)
	{
		perror("open /dev/null");
		_exit(1);
	}
	if (dup2(dev_null, 0) == -1)
	{
		perror("dup2 /dev/null");
		close(dev_null);
		_exit(1);
	}
	close(dev_null);
}

static void	px_setup_infile(int fd_in)
{
	if (dup2(fd_in, 0) == -1)
	{
		perror("dup2 infile");
		_exit(1);
	}
	close(fd_in);
}

static void	px_setup_input_child_1(int fd_in)
{
	if (fd_in >= 0)
		px_setup_infile(fd_in);
	else
		px_setup_input_null();
}

void	px_child1(t_pipex *px)
{
	px_setup_input_child_1(px->fd_in);
	if (dup2(px->fd_pipe[1], 1) == -1)
	{
		perror("dup2 pipe write");
		_exit(1);
	}
	px_close_fd_except(&px->fd_pipe[1], 1);
	px_close_fd(&px->fd_pipe[0]);
	px_close_fd(&px->fd_out);
	px_execve_cmd(px->argv[2], px->envp);
}

void	px_child2(t_pipex *px)
{
	if (dup2(px->fd_pipe[0], 0) == -1)
	{
		perror("dup2 pipe read");
		_exit(1);
	}
	px_close_fd_except(&px->fd_pipe[0], 0);
	if (dup2(px->fd_out, 1) == -1)
	{
		perror("dup2 outfile");
		_exit(1);
	}
	px_close_fd_except(&px->fd_out, 1);
	px_close_fd(&px->fd_pipe[1]);
	px_execve_cmd(px->argv[3], px->envp);
}
