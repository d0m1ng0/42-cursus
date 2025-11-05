/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:06:42 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/19 11:44:19 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	l_nb;

	l_nb = nb;
	if (l_nb < 0)
	{
		ft_putchar('-');
		l_nb = (-1) * l_nb;
	}
	if (l_nb >= 10)
		ft_putnbr(l_nb / 10);
	ft_putchar(l_nb % 10 + '0');
}
/*
int	main(void)
{
	ft_putnbr(42);
		write(1, "\n", 1);
	ft_putnbr(-42);
		write(1, "\n", 1);
	ft_putnbr(0);
		write(1, "\n", 1);
	ft_putnbr(-2147483648);
		write(1, "\n", 1);
	ft_putnbr(2147483647);
	return (0);
}
*/
