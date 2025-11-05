/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:07:51 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 13:07:56 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict_parse.h"

/*
[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
trim space before (0-9i)
*/
static int	one_line(char *buf)
{
	char	*chk;

	chk = buf;
	while (*chk && (*chk != '\n'))
		chk++;
	if (*chk == '\n')
	{
		*chk++ = '\0';
		return ((int)(chk - buf));
	}
	return (0);
}

/*
	[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
*/
static char	*get_digit(t_nbr_str *dict, char *buf)
{
	int	i;

	i = 0;
	if (!is_digit(buf[i++]))
		return (NULL);
	dict->nbr = buf;
	while (buf[i] && is_digit(buf[i]))
		i++;
	if (buf[i] == ':')
	{
		buf[i] = '\0';
		return (buf + i + 1);
	}
	buf[i++] = '\0';
	while (buf[i] && (buf[i] != ':'))
		i++;
	if (buf[i] != ':')
		return (NULL);
	if (buf[i])
		return (buf + i + 1);
	return (NULL);
}

static int	line_to_struct(char *buf, t_nbr_str *dict)
{
	char	*chk;

	chk = get_digit(dict, buf);
	if (chk == NULL)
		return (1);
	while (*chk && is_space(*chk))
		chk++;
	if (!*chk)
		return (4);
	dict->str = chk;
	while (*chk && !is_eol(*chk))
		chk++;
	while (is_space(*(chk - 1)))
		chk--;
	*chk = '\0';
	return (0);
}

static void	dict_free_last(t_nbr_str *dict)
{
	if (dict->nbr)
		return ;
	dict->prev->next = NULL;
	free(dict);
}

int	parse_buf_to_dict(char *buf, t_nbr_str *dict)
{
	char		*chk;
	int			siz;

	chk = buf;
	siz = one_line(chk);
	while (siz)
	{
		if (siz == 1)
		{
			siz = one_line(++chk);
			continue ;
		}
		if (line_to_struct(chk, dict))
			return (0);
		if (dict_add_next(dict))
			return (0);
		dict = dict->next;
		chk += siz;
		siz = one_line(chk);
	}
	dict_free_last(dict);
	return (1);
}
