/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:54:21 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 19:40:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_rotate(t_dlist **stack)
{
	t_dlist	*top;
	t_dlist	*bottom;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	top = *stack;
	bottom = ft_dlstlast(*stack);
	*stack = top->next;
	(*stack)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}

void	ra(t_dlist **stack_a, int relay)
{
	ps_rotate(stack_a);
	if (relay == ON)
		ft_putendl_fd("ra", 1);
}

void	rb(t_dlist **stack_b, int relay)
{
	ps_rotate(stack_b);
	if (relay == ON)
		ft_putendl_fd("rb", 1);
}

void	rr(t_dlist **stack_a, t_dlist **stack_b, int relay)
{
	ra(stack_a, OFF);
	rb(stack_b, OFF);
	if (relay == ON)
		ft_putendl_fd("rr", 1);
}
/*
LESSON
Cut the head and put it to the tail:
Control and return if problems.
Define the top and the bottom of the stack.
The second node becomes the new node.
The old top goes after bottom.
*/
