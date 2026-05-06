/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:07:52 by dverdini          #+#    #+#             */
/*   Updated: 2026/01/23 18:43:58 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_l;

	n_l = n;
	if (n_l < 0)
	{
		n_l = -n_l;
		ft_putchar_fd('-', fd);
	}
	if (n_l >= 10)
	{
		ft_putnbr_fd(n_l / 10, fd);
	}
	ft_putchar_fd(n_l % 10 + '0', fd);
}

int counter(void)
{
	static	int i;

	i = 0;
	i++;
	return (i);
}

int	main(void)
{
	int	i;
	int	fd;
	int	result;
	i = 10;
	fd = 1;
	result = 0;
	while (i++ < 10)
		result = counter();
	ft_putnbr_fd(result, fd);
	return (0);
}
