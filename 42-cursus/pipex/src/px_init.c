/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:08:35 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/30 21:11:52 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_init_files(char **argv, int *fd_in, int *fd_out)
{
	*fd_in = px_open_infile(argv[1]);
	*fd_out = px_open_outfile(argv[4]);
	if (*fd_in < 0)
		perror(argv[1]);
	if (*fd_out < 0)
	{
		if (*fd_in >= 0)
			close(*fd_in);
		write(2, "pipex: ", 7);
		perror(argv[4]);
		return (1);
	}
	return (0);
}
