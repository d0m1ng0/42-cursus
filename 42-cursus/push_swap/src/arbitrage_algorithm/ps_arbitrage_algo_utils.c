/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arbitrage_algo_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:17:11 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 18:40:10 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ps_prepare_nodes(t_dlist *stack_a, t_dlist *stack_b)
{
	set_pos_elem(stack_a);
	set_pos_elem(stack_b);
	set_target_a(stack_a, stack_b);
	set_move_best_count(stack_a, stack_b);
	set_convenient(stack_a);
}
//SET MOVE BEST COUNT: calculate the cost for every move applying discounts

int	ft_max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

//set target: fir every number in stack_a find the perfect match in stack_b
t_dlist	*point_to_max(t_dlist *stack)
{
	t_dlist	*node_max;
	long	max;

	max = LONG_MIN;
	while (stack)
	{
		if (*(int *)stack->content > max)
		{
			max = *(int *)stack->content;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_max);
}

t_dlist	*point_to_min(t_dlist *stack)
{
	t_dlist	*node_min;
	long	min;

	min = LONG_MAX;
	while (stack)
	{
		if (*(int *)stack->content < min)
		{
			min = *(int *)stack->content;
			node_min = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_dlist	*get_convenient(t_dlist *stack_a)
{
	while (stack_a)
	{
		if (stack_a->convenient == true)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (stack_a);
}
