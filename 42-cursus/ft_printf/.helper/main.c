/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:17:28 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 13:28:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
