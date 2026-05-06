/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:49:18 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 16:06:03 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_swap(t_dlist *stack)
{
	void	*content_tmp;
	int		index_tmp;

	if (!stack || !stack->next)
		return ;
	content_tmp = stack->content;
	stack->content = (stack->next)->content;
	(stack->next)->content = content_tmp;
	index_tmp = stack->index;
	stack->index = (stack->next)->index;
	(stack->next)->index = index_tmp;
}

void	sa(t_dlist **stack_a, int relay)
{
	ps_swap(*stack_a);
	if (relay == ON)
		ft_putendl_fd("sa", 1);
}

void	sb(t_dlist **stack_b, int relay)
{
	ps_swap(*stack_b);
	if (relay == ON)
		ft_putendl_fd("sb", 1);
}

void	ss(t_dlist **stack_a, t_dlist **stack_b, int relay)
{
	sa(stack_a, OFF);
	sb(stack_b, OFF);
	if (relay == ON)
		ft_putendl_fd("ss", 1);
}
