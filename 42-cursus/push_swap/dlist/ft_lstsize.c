/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:42:33 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:35:35 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_dlist *lst)
{
	int	l_lst;

	l_lst = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		l_lst++;
	}
	return (l_lst);
}
