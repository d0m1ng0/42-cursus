/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 23:29:54 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/30 23:31:37 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_wait_children(pid_t pid1, pid_t pid2)
{
	int	status;

	status = 0;
	if (waitpid(pid2, &status, 0) == -1)
	{
		waitpid(pid1, NULL, 0);
		return (px_error());
	}
	waitpid(pid1, NULL, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
