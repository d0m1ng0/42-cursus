/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:32:31 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 14:44:32 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fdl(unsigned int n, char type, int fd)
{
	int		len;
	char	*base;

	len = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_puthex_fdl(n / 16, type, fd);
	}
	len += ft_putchar_fdl(base[n % 16], fd);
	return (len);
}
