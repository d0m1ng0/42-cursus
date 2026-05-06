/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:28:39 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 12:45:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ps_execute_move(char *line, t_dlist **a, t_dlist **b)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(a, b, OFF);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, OFF);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, OFF);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, OFF);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, OFF);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, OFF);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, OFF);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, OFF);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, OFF);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, OFF);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, OFF);
	else
		return (-1);
	return (0);
}

void	ps_read_and_execute_moves(t_dlist **stack_a, t_dlist **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ps_execute_move(line, stack_a, stack_b) == -1)
		{
			free(line);
			ps_free_stack(stack_a);
			ps_free_stack(stack_b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**str_values;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	str_values = ps_init_str_values(argc, argv);
	if (!str_values)
		return (ft_putstr_fd("Error\n", 2), 1);
	ps_parse_and_fill_stack(&stack_a, str_values);
	ps_free_str_values(str_values);
	ps_read_and_execute_moves(&stack_a, &stack_b);
	if (ps_is_sorted(stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
