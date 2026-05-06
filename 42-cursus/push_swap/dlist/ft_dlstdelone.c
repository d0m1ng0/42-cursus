/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:52:35 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/03 21:02:54 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst || !del)
		return ;
	del(dlst->content);
	free(dlst);
}
