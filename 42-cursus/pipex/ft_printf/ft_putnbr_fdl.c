/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:29:18 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 14:30:09 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fdl(int n, int fd)
{
	long	n_l;
	int		len;

	n_l = n;
	len = 0;
	if (n_l < 0)
	{
		n_l = -n_l;
		len += ft_putchar_fdl('-', fd);
	}
	if (n_l >= 10)
	{
		len += ft_putnbr_fdl(n_l / 10, fd);
	}
	len += ft_putchar_fdl(n_l % 10 + '0', fd);
	return (len);
}
