/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnum_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:42:59 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/24 17:43:00 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charnum_print.h"

int	is_seg(char *buf)
{
	if (buf[0] != '1')
		return (0);
	if (!buf[1] || buf[1] != '0')
		return (0);
	if (!buf[2] || (buf[2] != '0'))
		return (0);
	buf += 2;
	while (*buf)
		if (*buf++ != '0')
			return (0);
	return (1);
}

int	print_full(t_nbr_str *dict, char *buf)
{
	t_nbr_str	*match;
	t_nbr_str	*one;

	match = dict_find(dict, buf);
	if (match == NULL)
		return (0);
	if (is_seg(buf))
	{
		one = dict_find(dict, "1");
		ft_putstr(one->str);
		ft_putstr(" ");
	}
	ft_putstr(match->str);
	return (1);
}

int	print_seg(t_nbr_str *dict, int seg)
{
	t_nbr_str	*match;

	match = dict_find_seg(dict, seg);
	if (match == NULL)
		return (-1);
	ft_putstr(" ");
	ft_putstr(match->str);
	return (0);
}

int	print_unit(int *sp, t_nbr_str *dict, char unit)
{
	t_nbr_str	*match;

	if (unit == '0')
		return (0);
	match = dict_find_char(dict, unit);
	if (match == NULL)
		return (-1);
	if (*sp)
		ft_putstr(" ");
	else
		*sp = 1;
	ft_putstr(match->str);
	return (0);
}

int	print_nnn(int *sp, t_nbr_str *dict, char *buf)
{
	t_nbr_str	*match;
	t_nbr_str	*one;

	if (buf[0] == '0')
		return (0);
	match = dict_find(dict, buf);
	if (match == NULL)
		return (0);
	if (is_seg(buf))
	{
		one = dict_find(dict, "1");
		if (*sp)
			ft_putstr(" ");
		else
			*sp = 1;
		ft_putstr(one->str);
	}
	if (*sp)
		ft_putstr(" ");
	else
	*sp = 1;
	ft_putstr(match->str);
	return (1);
}
