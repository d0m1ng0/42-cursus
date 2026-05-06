/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:00:26 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:54:49 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**argv;
	char	**envp;
}	t_pipex;

void	free_split(char **string);
int		px_open_infile(char *path);
int		px_open_outfile(char *path);
int		px_init_files(char **argv, int *fd_in, int *fd_out);
void	px_close_all(int fd_in, int fd_out, int fd_pipe[2]);
void	px_close_fd(int *fd);
void	px_close_fd_except(int *fd, int except);
void	px_child1(t_pipex *px);
void	px_close_after_child1(int *fd_in, int fd_pipe[2]);
void	px_child2(t_pipex *px);
pid_t	px_fork_child1(t_pipex *px);
pid_t	px_fork_child2(t_pipex *px);
int		px_wait_children(pid_t pid1, pid_t pid2);
char	*px_extract_path_value(char **envp);
char	*px_create_path_candidate(char *dir, char *cmd);
char	*px_find_cmd_dir(char *cmd, char **envp);
void	px_execve_cmd(char *cmd_str, char **envp);
int		px_arg_error(void);
int		px_error(void);

#endif
