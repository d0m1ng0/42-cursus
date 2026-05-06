/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:30:18 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 19:36:55 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_reverse_rotate(t_dlist **stack)
{
	t_dlist	*bottom;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	bottom = ft_dlstlast(*stack);
	(bottom->prev)->next = NULL;
	bottom->prev = NULL;
	ft_dlstadd_front(stack, bottom);
}

void	rra(t_dlist **stack_a, int relay)
{
	ps_reverse_rotate(stack_a);
	if (relay == ON)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_dlist **stack_b, int relay)
{
	ps_reverse_rotate(stack_b);
	if (relay == ON)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_dlist **stack_a, t_dlist **stack_b, int relay)
{
	rra(stack_a, OFF);
	rrb(stack_b, OFF);
	if (relay == ON)
		ft_putendl_fd("rrr", 1);
}
/*
LESSON
Cut the tail and put it to the head:
Conrol and return if problems.
Define the bottom and the top of the stack.
The node at the bottom becomes the top node.
*/
