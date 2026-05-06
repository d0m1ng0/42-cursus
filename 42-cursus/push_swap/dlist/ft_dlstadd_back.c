/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:18:57 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:34:58 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!dlst || !new)
		return ;
	if (*dlst == NULL)
	{
		*dlst = new;
	}
	else
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
}
