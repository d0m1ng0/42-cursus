/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:26:20 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 14:34:47 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*str)
	{
		str++;
	}
	return (str - start);
}
/*
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

int	ft_puthex_fdl(unsigned int n, char type, int fd)
{
	int	len;
	char *base;

	len = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_puthex_fdl(n / 16, type, fd);
	}
	len += ft_putchar_fdl(base[n % 16],  fd);
	return (len);
}

int	ft_putptr_fdl(unsigned long n, int fd)
{
	int	len;
	char *base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putptr_fdl(n / 16, fd);
	len += ft_putchar_fdl(base[n % 16],  fd);
	return (len);
}
*/
