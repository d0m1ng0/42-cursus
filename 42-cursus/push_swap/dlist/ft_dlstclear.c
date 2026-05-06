/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:19:27 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/03 21:02:43 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*dlst_backup;
	t_dlist	*dlst_run;

	if (!dlst || !del)
		return ;
	dlst_run = *dlst;
	while (dlst_run)
	{
		dlst_backup = dlst_run->next;
		ft_dlstdelone(dlst_run, del);
		dlst_run = dlst_backup;
	}
	*dlst = NULL;
}
