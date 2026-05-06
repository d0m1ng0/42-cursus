/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:41:28 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/30 21:23:49 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **string)
{
	int	i;

	if (!string)
		return ;
	i = 0;
	while (string[i])
		free(string[i++]);
	free(string);
}
