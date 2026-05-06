/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:46:33 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/27 12:48:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_arg_error(void)
{
	write(2, "pipex: bad arguments\n", 21);
	return (1);
}

int	px_error(void)
{
	write(2, "pipex\n", 6);
	return (1);
}
