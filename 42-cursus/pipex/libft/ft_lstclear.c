/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:35:50 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:38:35 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_backup;
	t_list	*lst_run;

	if (!lst || !del)
		return ;
	lst_run = *lst;
	while (lst_run)
	{
		lst_backup = lst_run->next;
		ft_lstdelone(lst_run, del);
		lst_run = lst_backup;
	}
	*lst = NULL;
}
