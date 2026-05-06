/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_getpid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:51:21 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/26 13:57:31 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	pid_t	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		ft_printf("Sono il CHILD (pid=%d)\n", getpid());
	else
		ft_printf("Sono il PARENT (pid=%d), child pid=%d\n", getpid(), pid);
	return (0);
}
