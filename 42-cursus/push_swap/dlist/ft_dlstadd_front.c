/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:40:05 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/17 12:54:04 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dlist	*ft_dlstnew(void *content);

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	if (!new || !dlst)
		return ;
	new->next = *dlst;
	new->prev = NULL;
	if (*dlst)
		(*dlst)->prev = new;
	*dlst = new;
}
