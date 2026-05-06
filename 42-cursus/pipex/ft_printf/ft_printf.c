/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:07:55 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 08:28:03 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char type, t_printf_data(*data))
{
	unsigned long	ptr;

	if (type == 'c')
		data->l_t += ft_putchar_fdl(va_arg(args, int), 1);
	else if (type == 's')
		data->l_t += ft_putstr_fdlsec(va_arg(args, char *), 1);
	else if (type == 'd' || type == 'i')
		data->l_t += ft_putnbr_fdl(va_arg(args, int), 1);
	else if (type == 'u')
		data->l_t += ft_putuint_fdl(va_arg(args, unsigned int), 1);
	else if (type == 'x' || type == 'X')
		data->l_t += ft_puthex_fdl(va_arg(args, unsigned int), type, 1);
	else if (type == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			data->l_t += write(1, "(nil)", 5);
		else
		{
			data->l_t += write(1, "0x", 2) + ft_putptr_fdl(ptr, 1);
		}
	}
	else if (type == '%')
		data->l_t += ft_putchar_fdl('%', 1);
	return (data->l_t);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_printf_data	data;
	int				i;

	va_start(args, format);
	data.l_t = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_formats(args, format[i + 1], &data);
			i++;
		}
		else
			data.l_t += ft_putchar_fdl(format[i], 1);
		i++;
	}
	va_end(args);
	return (data.l_t);
}
