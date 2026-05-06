/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arbitrage_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:52:01 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 20:41:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_sort_three(t_dlist **a)
{
	t_dlist	*node_max;

	node_max = point_to_max(*a);
	if (*a == node_max)
		ra(a, ON);
	else if ((*a)->next == node_max)
		rra(a, ON);
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a, ON);
}

void	ps_rotation_final(t_dlist **stack)
{
	t_dlist	*node_min;

	set_pos_elem(*stack);
	node_min = point_to_min(*stack);
	while (*stack != node_min)
	{
		if (node_min->median_up)
			ra(stack, ON);
		else
			rra(stack, ON);
	}
}

void	ps_arbitrage_algo(t_dlist **stack_a, t_dlist **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		return (ps_sort_three(stack_a));
	}
	pb(stack_b, stack_a, ON);
	pb(stack_b, stack_a, ON);
	while (ft_lstsize(*stack_a) > 3)
	{
		ps_prepare_nodes(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	ps_sort_three(stack_a);
	while (*stack_b)
	{
		set_pos_elem(*stack_a);
		set_pos_elem(*stack_b);
		set_target_b(*stack_b, *stack_a);
		move_b_to_a(stack_b, stack_a);
	}
	ps_rotation_final(stack_a);
}
/*
LESSON
ps_arbitrage_algo:
1. BASE CASE: If 3 nodes remain, use os_sort_three for immediate sorting.
2. INIZIALIZATION: Push 2 elements to stack b to establish a comparison base.
3. COST OPTIMIZATION (a->b): Loop until 3 nodes remain in a. At each step.
calculate the most conveninet arbitrage move to keep b descending-ish.
4. REINTEGRATION (b->a): Push all elements back to A, ensuring they fit between
their correct targets.
5. FINAL ALLIGNMENT: Perdorm a final rotation on stack a to bring the minimum
value to the top, completing the ascending sequence.
*/
