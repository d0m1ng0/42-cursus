/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:41:49 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 18:41:52 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_find.h"

static int	l_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/*
	search (dict) for (dict->nbr == nbr)
*/
t_nbr_str	*dict_find(t_nbr_str *dict, char *nbr)
{
	if (nbr == NULL)
		return (NULL);
	while (dict)
	{
		if (l_strcmp(nbr, dict->nbr) == 0)
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}

/*
	search dict for (dict->nbr == "(char c)"
*/
t_nbr_str	*dict_find_char(t_nbr_str *dict, char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	return (dict_find(dict, buf));
}

/*
	given a segment unit index
	build and serach for the corresponding
	qualifying string
*/
t_nbr_str	*dict_find_seg(t_nbr_str *dict, int seg)
{
	int		i;
	int		nzero;
	char	buf[1024];

	nzero = seg * 3;
	if (nzero < 3)
		return (NULL);
	i = 0;
	buf[i++] = '1';
	while (i <= nzero)
		buf[i++] = '0';
	buf[i] = '\0';
	return (dict_find(dict, buf));
}
