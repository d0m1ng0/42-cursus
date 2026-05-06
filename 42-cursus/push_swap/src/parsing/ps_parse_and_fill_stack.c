/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_and_fill_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:16:02 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:40:29 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ps_parse_and_fill_stack(t_dlist **stack_a, char **str_values)
{
	int		i;
	long	val;
	t_dlist	*val_node;

	i = 0;
	if (!str_values[i])
		ps_error(stack_a, str_values);
	while (str_values[i] != NULL)
	{	
		if (!ps_is_str_val_valid(str_values[i]))
			ps_error(stack_a, str_values);
		val = ft_atol(str_values[i]);
		if (val < INT_MIN || val > INT_MAX
			|| ps_str_values_has_duplicates(*stack_a, (int)val))
			ps_error(stack_a, str_values);
		val_node = ps_create_node((int)val);
		if (!val_node)
			ps_error(stack_a, str_values);
		ft_dlstadd_back(stack_a, val_node);
		i++;
	}
}
