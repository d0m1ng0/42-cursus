/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:16:58 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/03 21:03:05 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->next)
	{
		dlst = dlst->next;
	}
	return (dlst);
}
