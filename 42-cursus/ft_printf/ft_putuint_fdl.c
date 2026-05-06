/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:31:11 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 14:31:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_fdl(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putuint_fdl(n / 10, fd);
	}
	len += ft_putchar_fdl(n % 10 + '0', fd);
	return (len);
}
