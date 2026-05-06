/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arbitrage_algo_settings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:16:56 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:39:24 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_pos_elem(t_dlist *stack)
{
	int	count;
	int	median;

	median = ft_lstsize(stack) / 2;
	count = 0;
	while (stack)
	{
		stack->pos = count;
		if (count <= median)
			stack->median_up = true;
		else
			stack->median_up = false;
		stack = stack->next;
		count++;
	}
}

void	set_target_b(t_dlist *stack_b, t_dlist *stack_a)
{
	long	best_b_match;
	t_dlist	*node_target;
	t_dlist	*node_a;

	while (stack_b)
	{
		best_b_match = LONG_MAX;
		node_target = NULL;
		node_a = stack_a;
		while (node_a)
		{
			if (*(int *)node_a->content > *(int *)stack_b->content
				&& *(int *)node_a->content < best_b_match)
			{
				best_b_match = *(int *)node_a->content;
				node_target = node_a;
			}
			node_a = node_a->next;
		}
		if (best_b_match == LONG_MAX)
			stack_b->target = point_to_min(stack_a);
		else
			stack_b->target = node_target;
		stack_b = stack_b->next;
	}
}

void	set_target_a(t_dlist *stack_a, t_dlist *stack_b)
{
	long	best_a_match;
	t_dlist	*node_b;
	t_dlist	*node_target;

	while (stack_a)
	{
		best_a_match = LONG_MIN;
		node_target = NULL;
		node_b = stack_b;
		while (node_b)
		{
			if (*(int *)node_b->content < *(int *)stack_a->content
				&& *(int *)node_b->content > best_a_match)
			{
				best_a_match = *(int *)node_b->content;
				node_target = node_b;
			}
			node_b = node_b->next;
		}
		if (best_a_match == LONG_MIN)
			stack_a->target = point_to_max(stack_b);
		else
			stack_a->target = node_target;
		stack_a = stack_a->next;
	}
}

void	set_move_best_count(t_dlist *a, t_dlist *b)
{
	int	l_a;
	int	l_b;
	int	dist_a;
	int	dist_b;

	l_a = ft_lstsize(a);
	l_b = ft_lstsize(b);
	while (a)
	{
		dist_a = l_a - a->pos;
		dist_b = l_b - a->target->pos;
		if (a->median_up == true && a->target->median_up == true)
			a->best_move_count = ft_max(a->pos, a->target->pos);
		else if (a->median_up == false && a->target->median_up == false)
			a->best_move_count = ft_max(dist_a, dist_b);
		else
		{
			if (a->median_up == true)
				a->best_move_count = a->pos + dist_b;
			else
				a->best_move_count = a->target->pos + dist_a;
		}
		a = a->next;
	}
}

void	set_convenient(t_dlist *stack_a)
{
	long	most_convenient;
	t_dlist	*best_candidate;

	most_convenient = LONG_MAX;
	best_candidate = NULL;
	while (stack_a)
	{
		stack_a->convenient = false;
		if (stack_a->best_move_count < most_convenient)
		{	
			most_convenient = stack_a->best_move_count;
			best_candidate = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (best_candidate)
		best_candidate->convenient = true;
}
