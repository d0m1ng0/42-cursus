/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:58:29 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 19:41:05 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_push(t_dlist **stack_dst, t_dlist **stack_src)
{
	t_dlist	*node_to_push;

	if (!stack_src || !*stack_src)
		return ;
	node_to_push = *stack_src;
	*stack_src = node_to_push->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	ft_dlstadd_front(stack_dst, node_to_push);
}

void	pa(t_dlist **stack_dst, t_dlist **stack_src, int relay)
{
	ps_push(stack_dst, stack_src);
	if (relay == ON)
		ft_putendl_fd("pa", 1);
}

void	pb(t_dlist **stack_dst, t_dlist **stack_src, int relay)
{
	ps_push(stack_dst, stack_src);
	if (relay == ON)
		ft_putendl_fd("pb", 1);
}
/*
LESSON
1. Security check: if stack does not exists return.
2. Take the first node of the stack_src.
3. Thehead of the source becomes the next node.
4. If exists a new node in the stack_src punt to NULL its previous.
*/
