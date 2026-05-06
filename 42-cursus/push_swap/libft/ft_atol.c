/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:13:17 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/03 17:18:37 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13)
		|| c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	sign;
	long	nptr_converted;

	i = 0;
	sign = 1;
	nptr_converted = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = (-1) * sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nptr_converted = nptr_converted * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nptr_converted);
}
