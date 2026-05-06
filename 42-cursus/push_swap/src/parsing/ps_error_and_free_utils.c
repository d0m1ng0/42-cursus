/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_and_free_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:25:51 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:40:21 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ps_free_str_values(char **str_values)
{
	int	i;

	if (!str_values)
		return ;
	i = 0;
	while (str_values[i])
	{
		free (str_values[i]);
		i++;
	}
	free (str_values);
}

void	ps_free_stack(t_dlist **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_dlstclear(stack_a, free);
	*stack_a = NULL;
}

void	ps_error(t_dlist **stack_a, char **str_values)
{
	if (stack_a)
		ps_free_stack(stack_a);
	if (str_values)
	{
		ps_free_str_values(str_values);
	}
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
/*
LESSON
exit (1) or 2 3 ,  ..., 255 mean FAILURE
exit (0) is			 SUCCESS
*/
