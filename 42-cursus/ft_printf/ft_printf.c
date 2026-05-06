/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:07:55 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 15:38:29 by dverdini         ###   ########.fr       */
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
/*
int	ft_formats(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + ft_putchar_fdl(va_arg(args, int), 1);
	else if ()
		count;
	else if ()
		count;
	else if ()
		count;
	else if ()
		count;
		count;
	else if ()
		count;
	else if ()
		count;
	return (len);
}
*/
/*
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
		{
			length += ft_putchar_fdl(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
*/
/*
#include "ft_printf.h"

int	main(void)
{
	int	*ptr1;
	int	*ptr2;
	int	n1;
	int	n2;

	n1 = 21;
	n2 = 49;
	ptr1 = &n1;
	ptr2 = &n2;
	ft_printf("Print a character: %c\n", 'z');
	ft_printf("Print a string: %s\n", "hello world");
	ft_printf("Print a number: %d\n", -42);
	ft_printf("Print an unsigned number: %u\n", -1);
	ft_printf("Print an hexadecimal x-format: %x\n", 42);
	ft_printf("Print an hexadecimal X-format: %X\n", 42);
	ft_printf("Print a pointer ptr1 address: %p\n", ptr1);
	ft_printf("Print a pointer ptr2 address: %p\n", ptr2);
	ft_printf("Print a NULL-pointer address: %p\n", NULL);
	ft_printf("%");
	return (0);
}
*/
