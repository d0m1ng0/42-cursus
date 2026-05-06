/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 22:57:21 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:55:44 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	px_fork_child1(t_pipex *px)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		px_close_all(px->fd_in, px->fd_out, px->fd_pipe);
		return (px_error());
	}
	if (pid1 == 0)
	{
		px_child1(px);
	}
	return (pid1);
}

pid_t	px_fork_child2(t_pipex *px)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		px_close_all(px->fd_in, px->fd_out, px->fd_pipe);
		waitpid(px->pid1, NULL, 0);
		return (px_error());
	}
	if (pid2 == 0)
		px_child2(px);
	return (pid2);
}
