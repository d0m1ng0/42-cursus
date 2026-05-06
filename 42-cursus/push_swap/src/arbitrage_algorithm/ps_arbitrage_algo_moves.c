/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arbitrage_algo_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:16:45 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 19:30:40 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_both_up_or_down(t_dlist **a, t_dlist **b, t_dlist *c)
{
	if (c->median_up && c->target->median_up)
		while (*a != c && *b != c->target)
			rr(a, b, ON);
	else if (!(c->median_up) && !(c->target->median_up))
		while (*a != c && *b != c->target)
			rrr(a, b, ON);
}

void	finish_rotation_a(t_dlist **a, t_dlist *c)
{
	while (*a != c)
	{
		if (c->median_up)
			ra(a, ON);
		else
			rra(a, ON);
	}
}

void	finish_rotation_b(t_dlist **b, t_dlist *c)
{
	while (*b != c->target)
	{
		if (c->target->median_up)
			rb(b, ON);
		else
			rrb(b, ON);
	}
}

void	move_a_to_b(t_dlist **a, t_dlist **b)
{
	t_dlist	*c;

	c = get_convenient(*a);
	rotate_both_up_or_down(a, b, c);
	finish_rotation_a(a, c);
	finish_rotation_b(b, c);
	pb(b, a, ON);
}

void	move_b_to_a(t_dlist **b, t_dlist **a)
{
	finish_rotation_a(a, (*b)->target);
	pa(a, b, ON);
}
/*
void	rotate_both_up(t_dlist **a, t_dlist **b, t_dlist *c)
{
	while (*a != c && *b != c->target)
		rr(a, b, ON);
}

void	rotate_both_down(t_dlist **a, t_dlist **b, t_dlist *c)
{
	while (*a != c && *b != c->target)
		rrr(a, b, ON);
}

void	move_a_to_b(t_dlist **a, t_dlist **b)
{
	t_dlist	*c;

	c = get_convenient(*a);
	if (c->median_up && c->target->median_up)
		rotate_both_up(a, b, c);
	else if (!(c->median_up) && !(c->target->median_up))
		rotate_both_down(a, b, c);
	finish_rotation_a(a, c);
	finish_rotation_b(b, c);
	pb(b, a, ON);
}
*/
