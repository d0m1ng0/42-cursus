/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnum_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:12:01 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/24 11:12:03 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charnum_write.h"

static int	print_0n0(int *sp, t_nbr_str *dict, char *buf)
{
	t_nbr_str	*match;

	buf[1] = '0';
	match = dict_find(dict, buf);
	if (match == NULL)
		return (-1);
	if (*sp)
		ft_putstr(" ");
	else
		*sp = 1;
	ft_putstr(match->str);
	return (0);
}

static int	print_0nn(int *sp, t_nbr_str *dict, char *buf)
{
	t_nbr_str	*match;

	if (buf[0] == '0')
		return (0);
	match = dict_find(dict, buf);
	if (match == NULL)
		return (print_0n0(sp, dict, buf));
	if (*sp)
		ft_putstr(" ");
	else
		*sp = 1;
	ft_putstr(match->str);
	return (2);
}

static int	print_n00(int *sp, t_nbr_str *dict, char *buf)
{
	t_nbr_str	*match;

	if (buf[0] == '0')
		return (0);
	match = dict_find_char(dict, buf[0]);
	if (match == NULL)
		return (-1);
	if (*sp)
		ft_putstr(" ");
	else
		*sp = 1;
	ft_putstr(match->str);
	match = dict_find(dict, "100");
	if (match == NULL)
		return (-1);
	ft_putstr(" ");
	ft_putstr(match->str);
	return (0);
}

/*
	ATTENTION : handle FAILED MATCHES
*/
static int	charnum_chunk(int *sp, t_charnum *cn, int n, t_nbr_str *dict)
{
	char	buf[4];
	char	unit;

	charnum_get_seg(cn, n, buf);
	if (buf_zero(buf))
		return (1);
	unit = buf[2];
	if (print_nnn(sp, dict, buf))
	{
		print_seg(dict, n);
		return (0);
	}
	print_n00(sp, dict, buf);
	if (print_0nn(sp, dict, buf + 1) != 2)
		print_unit(sp, dict, unit);
	print_seg(dict, n);
	return (0);
}

int	charnum_write(t_charnum *cn, t_nbr_str *dict)
{
	int		n;
	int		sp;

	if (print_full(dict, cn->buf))
		return (0);
	sp = 0;
	n = cn->nseg;
	while (n >= 0)
	{
		charnum_chunk(&sp, cn, n, dict);
		n--;
	}
	return (0);
}
