/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:46:05 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:40:43 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ps_is_str_val_valid(char *str_val)
{
	int		i;

	i = 0;
	if (!str_val)
		return (0);
	if (str_val[i] == '+' || str_val[i] == '-')
		i++;
	if (str_val[i] == '\0')
		return (0);
	while (str_val[i] != '\0')
	{
		if (!ft_isdigit(str_val[i]))
			return (0);
		i++;
	}
	return (1);
}

t_dlist	*ps_create_node(int val)
{
	int		*ptr_val;
	t_dlist	*val_node;

	ptr_val = (int *)malloc(sizeof(int));
	if (!ptr_val)
		return (NULL);
	*ptr_val = val;
	val_node = ft_dlstnew(ptr_val);
	if (!val_node)
	{
		free(ptr_val);
		return (NULL);
	}
	val_node->index = -42;
	return (val_node);
}

int	ps_str_values_has_duplicates(t_dlist *stack_a, int val)
{
	while (stack_a)
	{
		if (*(int *)stack_a->content == val)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/*
LESSON
	(int *)stack_a->content
It means: that void* is actuallyand int
Then we must deferentiate: take the value that is in that address
	 *(int *)stack_a->content 
	|-|
	take the value
	  |-----------------------
	 	of this address to int
Initialization for debug: 
	val_node->index = -42;
*/
