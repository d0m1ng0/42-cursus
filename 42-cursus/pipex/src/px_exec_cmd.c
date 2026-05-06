/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:00:56 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/30 20:16:14 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_close_std_fds(void)
{
	close(0);
	close(1);
}

void	px_execve_cmd(char *cmd_str, char **envp)
{
	char	**cmd;
	char	*path_user;

	cmd = ft_split(cmd_str, ' ');
	if (!cmd || !cmd[0])
	{
		free_split(cmd);
		px_close_std_fds();
		_exit(127);
	}
	path_user = px_find_cmd_dir(cmd[0], envp);
	if (!path_user)
	{
		write(2, "pipex: ", 7);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": command not found\n", 20);
		free_split(cmd);
		px_close_std_fds();
		_exit(127);
	}
	execve(path_user, cmd, envp);
	free(path_user);
	free_split(cmd);
	px_close_std_fds();
	_exit(126);
}
