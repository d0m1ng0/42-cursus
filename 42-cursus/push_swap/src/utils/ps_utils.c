/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 08:49:37 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 12:48:44 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_sorted(t_dlist *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

char	**ps_init_str_values(int argc, char **argv)
{
	char	**str_values;
	int		i;	

	if (argc == 2)
	{
		str_values = ft_split(argv[1], ' ');
		if (!str_values)
			return (NULL);
	}
	if (argc > 2)
	{
		str_values = malloc(sizeof(char *) * argc);
		if (!str_values)
			return (NULL);
		i = 0;
		while (i < argc - 1)
		{
			str_values[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		str_values[i] = NULL;
	}
	return (str_values);
}
