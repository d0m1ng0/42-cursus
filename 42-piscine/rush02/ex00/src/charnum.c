/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:28:28 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 20:28:29 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "charnum.h"

/*
	initialize a charnum with a digit-string
	calculate (once) its length (strlen)
	calculate (once) the number of 3-digit segments
*/
int	charnum_init(t_charnum *cn, char *num)
{
	cn->buf = num;
	cn->len = 0;
	while (num[cn->len])
	{
		if (!is_digit(num[cn->len++]))
			return (0);
	}
	cn->nseg = ((cn->len - 1) / 3);
	return (cn->len);
}

int	charnum_get_seg(t_charnum *cn, int seg, char buf[4])
{
	char	*chk;
	int		i;

	if (seg > cn->nseg)
		return (1);
	chk = cn->buf + cn->len - 1 - (seg * 3);
	i = 3;
	buf[i--] = '\0';
	while ((chk >= cn->buf) && (i >= 0))
	{
		buf[i--] = *chk--;
	}
	while (i >= 0)
		buf[i--] = '0';
	return (0);
}

int	buf_zero(char *buf)
{
	int	i;

	i = 0;
	while (i < 3)
		if (buf[i++] != '0')
			return (0);
	return (1);
}
