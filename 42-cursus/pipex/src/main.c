/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:43:39 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 08:02:55 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ./pipex infile "cmd1 args" "cm2 args" outfile =
	= < inflie cmd1 | cmd2 > outfile
*/

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		return (px_arg_error());
	px.argv = argv;
	px.envp = envp;
	px.fd_pipe[0] = -1;
	px.fd_pipe[1] = -1;
	if (px_init_files(argv, &px.fd_in, &px.fd_out) == 1)
		return (1);
	if (pipe(px.fd_pipe) == -1)
	{
		px_close_all(px.fd_in, px.fd_out, px.fd_pipe);
		return (px_error());
	}
	px.pid1 = px_fork_child1(&px);
	if (px.pid1 < 0)
		return (1);
	px_close_after_child1(&px.fd_in, px.fd_pipe);
	px.pid2 = px_fork_child2(&px);
	if (px.pid2 < 0)
		return (1);
	px_close_all(px.fd_in, px.fd_out, px.fd_pipe);
	return (px_wait_children(px.pid1, px.pid2));
}
/*
 * Versione funzionante da spezzare
int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	fd_pipe[2];
	int	dev_null;
	int	status;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (px_arg_error());
	fd_in = px_open_infile(argv[1]);
	fd_out = px_open_outfile(argv[4]);
	if (fd_in < 0)
		perror(argv[1]);
	if (fd_out < 0)
	{
		if (fd_in >= 0)
			close(fd_in);
		write(2, "pipex: ", 7);
		perror(argv[4]);
		return (1);
	}
	if (pipe(fd_pipe) == -1)
		return (px_error());
	pid1 = fork();
	if (pid1 < 0)
	{
		if (fd_in >= 0)
			close(fd_in);
		if (fd_out >= 0)
			close(fd_out);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		return (px_error());
	}
	if (pid1 == 0)
	{
		if (fd_in >=0)
		{
			if (dup2(fd_in, 0) == -1)
			{
				perror("dup2 infile");
				_exit(1);
			}
			close(fd_in);
		}
		else
		{
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
		if (dup2(fd_pipe[1], 1) == -1)
		{
			perror("dup2 pipe write");
			_exit(1);
		}
		if (fd_pipe[1] >=0 && fd_pipe[1] != 1)
		{
			close(fd_pipe[1]);
			fd_pipe[1] = -1;
		}
		if (fd_pipe[0] >= 0)
		{
			close(fd_pipe[0]);
			fd_pipe[0] = -1;
		}
		if (fd_out >= 0)
			close(fd_out);
		px_execve_cmd(argv[2], envp);
		perror("execve");
		_exit(127);
	}
	close(fd_pipe[1]);
	fd_pipe[1] = -1;
	if (fd_in >=0)
	{
		close(fd_in);
		fd_in = -1;
	}
	//second child
	pid2 = fork();
	if (pid2 < 0)
	{
		if (fd_in >= 0)
			close(fd_in);
		if (fd_out >= 0)
			close(fd_out);
		if (fd_pipe[0] >= 0)
			close(fd_pipe[0]);
		waitpid(pid1, NULL, 0);
		return (px_error());
	}
	if (pid2 == 0)
	{
		if (dup2(fd_pipe[0], 0) == -1)
		{		
			perror("dup2 pipe read");
			_exit(1);
		}
		if (fd_pipe[0] >= 0 && fd_pipe[0] != 0)
		{
			close(fd_pipe[0]);
			fd_pipe[0] = -1;
		}
		if (dup2(fd_out, 1) == -1)
		{
			perror("dup2 outfile");
			_exit(1);
		}
		if (fd_out >= 0 && fd_out != 1)
		{
			close(fd_out);
			fd_out = -1;
		}
		px_execve_cmd(argv[3], envp);
		perror("execve");
		_exit(127);
	}
	if ((fd_pipe[0]) >= 0)
	{
		close(fd_pipe[0]);	
		fd_pipe[0] = -1;
	}
	if (fd_out >= 0)
	{
		close(fd_out);
		fd_out = -1;
	}
	if ((fd_in) >= 0)
	{
		close(fd_in);
		fd_in = -1;	
	}
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
*/
/*
//VERSIONE CAPITA FINO AL REFACTORING
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include <stdlib.h>

//free split
void	free_split(char **string)
{
	int	i;

	if (!string)
		return;
	i = 0;
	while(string[i])
		free(string[i++]);
	free(string);
}

int	px_open_infile(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	px_open_outfile(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}
static int  px_arg_error(void)
{
	write(2, "pipex: bad arguments\n", 21);
	return (1);
}
static int  px_error(void)
{
	write(2, "pipex\n", 6);
	return (1);
}

static int  px_enverror(void)
{
	write(2, "execve\n", 6);
	return (1);
}

//
static char	*px_extract_path_value(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*px_create_path_candidate(char *dir, char *cmd)
{
	char	*tmp;
	char	*path_candidate;

	if (!dir || !cmd)
		return (NULL);
	tmp = ft_strjoin(dir, "/");
	if (tmp == NULL)
		return (NULL);
	path_candidate = ft_strjoin(tmp, cmd);
	free(tmp);
	if (path_candidate == NULL)
		return (NULL);
	return (path_candidate);
}

static char	*px_find_cmd_dir(char *cmd, char **envp)
{
	char	*path_to_search;
	int		i;
	char	*dir_candidate;
	char	**dirs;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
    		return (ft_strdup(cmd));
	path_to_search = px_extract_path_value(envp);
	if (!path_to_search)
		return (NULL);
	dirs = ft_split(path_to_search, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		dir_candidate = px_create_path_candidate(dirs[i], cmd);
		if (dir_candidate && access(dir_candidate, X_OK) == 0)
		{
			free_split(dirs);
			return (dir_candidate);
		}
		free (dir_candidate);
		i++;
	}
	free_split(dirs);
	return (NULL);
}
static void	px_execve_cmd(char *cmd_str,char **envp)
{
	char	**cmd;
	char	*path_user;

	cmd = ft_split(cmd_str, ' ');
	if (!cmd || !cmd[0])
		_exit(127);

	path_user = px_find_cmd_dir(cmd[0], envp);
	if (!path_user)
	{
		free_split(cmd);
		_exit(127);
	}
	execve(path_user, cmd, envp);
	free(path_user);
	free_split(cmd);
	_exit(126);
}

//int	main(int argc, char **argv)
int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	fd_pipe[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		return (px_arg_error());
	fd_in = px_open_infile(argv[1]);	
	fd_out = px_open_outfile(argv[4]);
	if (fd_in < 0 || fd_out < 0)
	{
		write(2, "pipex: file error\n", 18);
		return (1);
	}
	if (pipe(fd_pipe) == -1)
		return (px_error());
	pid1 = fork();
	if (pid1 < 0)
	{
		close(fd_in);
		close(fd_out);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		return (px_error());
	}

	if (pid1 == 0)
	{
		dup2(fd_in, 0);
		dup2(fd_pipe[1], 1);
		close(fd_in);
		close(fd_out);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		//execve("/bin/cat", (char *const[]){"cat", NULL}, envp);
		px_execve_cmd(argv[2], envp);
	//	px_enverror();
	//	_exit(1);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		close(fd_in);
		close(fd_out);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		waitpid(pid1, NULL, 0);
		return (px_error());
	}
	if (pid2 == 0)
	{
		dup2(fd_pipe[0], 0);
		dup2(fd_out, 1);
		close(fd_out);
		close(fd_in);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		//execve("/usr/bin/wc", (char *const[]){"wc", NULL}, envp);
		px_execve_cmd(argv[3], envp);
	//	px_enverror();
	//	_exit(1);
	}

	close(fd_pipe[1]);
	close(fd_pipe[0]);
	close(fd_out);
	close(fd_in);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
*/

//#include <unistd.h>
//#include <stdlib.h>
//#include <fcntl.h>
//#include <sys/wait.h>
//#include <stdio.h>
///*
//static void	die(const char *msg)
//{
//	perror(msg);
//	exit(1);
//}
//
///*
// * WARNING: qui assumiamo che argv[2] e argv[3] siano comandi SENZA argomenti
// * es: "cat" "wc"
// * Per comandi con argomenti ("grep a"), servirà split.
// */
//int	main(int argc, char **argv, char **envp)
//{
//	int		in_fd;
//	int		out_fd;
//	int		pfd[2];
//	pid_t	pid1;
//	pid_t	pid2;
//
//	if (argc != 5)
//	{
//		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
//		return (1);
//	}
//
//	in_fd = open(argv[1], O_RDONLY);
//	if (in_fd < 0)
//		die("open infile");
//
//	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//	if (out_fd < 0)
//		die("open outfile");
//
//	if (pipe(pfd) < 0)
//		die("pipe");
//
//	/* child 1: cmd1 */
//	pid1 = fork();
//	if (pid1 < 0)
//		die("fork");
//	if (pid1 == 0)
//	{
//		dup2(in_fd, STDIN_FILENO);   /* stdin <- file1 */
//		dup2(pfd[1], STDOUT_FILENO); /* stdout -> pipe write */
//
//		close(in_fd);
//		close(out_fd);
//		close(pfd[0]);
//		close(pfd[1]);
//
//		/* per ora execve senza PATH: prova con "/bin/cat" ecc */
//		execve(argv[2], (char *const[]){argv[2], NULL}, envp);
//		perror("execve cmd1");
//		exit(127);
//	}
//
//	/* child 2: cmd2 */
//	pid2 = fork();
//	if (pid2 < 0)
//		die("fork");
//	if (pid2 == 0)
//	{
//		dup2(pfd[0], STDIN_FILENO);  /* stdin <- pipe read */
//		dup2(out_fd, STDOUT_FILENO); /* stdout -> file2 */
//
//		close(in_fd);
//		close(out_fd);
//		close(pfd[0]);
//		close(pfd[1]);
//
//		execve(argv[3], (char *const[]){argv[3], NULL}, envp);
//		perror("execve cmd2");
//		exit(127);
//	}
//
//	/* parent: close everything + wait */
//	close(in_fd);
//	close(out_fd);
//	close(pfd[0]);
//	close(pfd[1]);
//
//	waitpid(pid1, NULL, 0);
//	waitpid(pid2, NULL, 0);
//	return (0);
//}
/*
int main(int argc, char *argv[])
{
	int    pipefd[2];
	char   buf;
	pid_t  cpid;

	ft_printf("# --- ft_printf WORKS!\n");
	if (argc != 2)
	{
		ft_printf("# --- ERROR MESSAGE ---\n");
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (pipe(pipefd) == -1)
		err(EXIT_FAILURE, "pipe");
	
	cpid = fork();
	if (cpid == -1)
	    
	    err(EXIT_FAILURE, "fork");
	
	if (cpid == 0) {    // Child reads from pipe //
	    if (close(pipefd[1]) == -1)  // Close unused write end //
	        err(EXIT_FAILURE, "close");
	
	    while (read(pipefd[0], &buf, 1) > 0) {
	        if (write(STDOUT_FILENO, &buf, 1) != 1)
	            err(EXIT_FAILURE, "write");
	    }
	
	    if (write(STDOUT_FILENO, "\n", 1) != 1)
	        err(EXIT_FAILURE, "write");
	    if (close(pipefd[0]) == -1)
	        err(EXIT_FAILURE, "close");
	    _exit(EXIT_SUCCESS);
	
	} else {            // Parent writes argv[1] to pipe //
	    if (close(pipefd[0]) == -1)  // Close unused read end //
	        err(EXIT_FAILURE, "close");
	    if ((size_t)write(pipefd[1], argv[1], strlen(argv[1])) 
	    	!= strlen(argv[1]))
	        err(EXIT_FAILURE, "write");
	    if (close(pipefd[1]) == -1)  // Reader will see EOF //
	        err(EXIT_FAILURE, "close");
	    if (wait(NULL) == -1)        // Wait for child //
	        err(EXIT_FAILURE, "wait");
	    exit(EXIT_SUCCESS);
	}
}
*/
/*
LESSON

- exit():
The C standard specifies two constants, EXIT_SUCCESS and EXIT_FAILURE, that
may be passed to exit() to indicate successful or unsuccessful termination,
respectively.  RETURN VALUE The exit() function does not return. 

- NFRASTRUTTURA pipe() PIPE INIETTA DENTRO L ARRAY PASSATO COME ARGOMENTO due
file descriptor int	pipe(int pipefd[2]); DESCRIPTION pipe()  creates a
pipe, a unidirectional data channel that can be used for interprocess
communication.  The array pipefd is used to return two file descriptors
referring to the ends of the pipe.  pipefd[0] refers to the read end of the
pipe.  pipefd[1] refers to the write end of the pipe.  Data written to the
write end of the pipe is buffered by the kernel until it is read from the read
end of the pipe.  For further details, see pipe(7).

RETURN VALUE On success, zero is returned.  On error, -1 is returned, errno is
set to indicate the error, and pipefd is left unchanged.

       On Linux (and other systems), pipe() does not modify pipefd on failure.
       A requirement standardizing this behavior was added in POSIX.1-2008
       TC2.  The Linux-specific pipe2() system call likewise does not modify
       pipefd on failure.

TO SEE THE ERROR : ulimit -n 4; ./pipex hello


- MOLTIPLICAZIONE fork() DESCRIPTION The child process is an exact duplicate
of the parent preocess except for the following points the child has its own
unique process ID, and this PID does not match the ID of any exixting process
group or session.

the child's parent process id is the same asd the parent's process ID the
child does not inherites it's parent memory locks ...

RETURN ON success the PID of the chikd process is returned in the aprent, and
0 is returned in the child. On failure -1 is returned, no child process is
created, and errno is set to indicate the error.

 * */
