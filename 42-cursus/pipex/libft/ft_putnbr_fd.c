/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:05:08 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:41:37 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
