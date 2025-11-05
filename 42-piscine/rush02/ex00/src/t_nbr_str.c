/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_nbr_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:22:02 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 16:22:05 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_nbr_str.h"
/*
	malloc sufficient memory for a (t_nbr_str)
	initialize all members to NULL
	ATTN : caller is responsible for freeing this memory
*/
t_nbr_str	*dict_create(void)
{
	t_nbr_str	*dict;

	dict = (t_nbr_str *) malloc(sizeof(t_nbr_str));
	if (dict == NULL)
		return (NULL);
	dict->nbr = NULL;
	dict->str = NULL;
	dict->next = NULL;
	dict->prev = NULL;
	return (dict);
}

/*
	free memory for an entire linked-list
	this should be called with the root node
	of the list
*/
void	dict_release(t_nbr_str *dict)
{
	t_nbr_str	*next;

	while (dict)
	{
		next = dict->next;
		free(dict);
		dict = next;
	}
}

int	dict_add_next(t_nbr_str *dict)
{
	dict->next = dict_create();
	if (dict->next == NULL)
		return (1);
	dict->next->prev = dict;
	return (0);
}

/*
	print the data (nbr / str)
*/
void	dict_print(t_nbr_str *dict)
{
	if (dict->nbr)
	{
		ft_putstr("nbr (");
		ft_putstr(dict->nbr);
		ft_putstr(")\n");
	}
	if (dict->str)
	{
		ft_putstr("str (");
		ft_putstr(dict->str);
		ft_putstr(")\n");
	}
}

/*
	print the entire linked list
	this should be called with the root node
*/
void	dict_print_all(t_nbr_str *dict)
{
	while (dict)
	{
		dict_print(dict);
		dict = dict->next;
	}
}
