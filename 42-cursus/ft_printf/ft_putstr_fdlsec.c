/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdlsec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:28:43 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 14:28:48 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fdlsec(char *s, int fd)
{
	int	l;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else
	{
		l = ft_strlen(s);
		write(fd, s, l);
	}
	return (l);
}
