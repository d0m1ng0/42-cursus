/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:16:08 by dverdini          #+#    #+#             */
/*   Updated: 2025/12/15 20:54:24 by dverdini         ###   ########.fr       */
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nptr_converted;

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

/*
	DESCRIPTION
		The atoi() function converts the initial portion of the 
		string pointed to by nptr to int.
		The behavior is the same as
           	strtol(nptr, NULL, 10); except that atoi() does not detect 
		errors.
		The atol() and atoll() functions behave the same as atoi(), 
		except that they convert the  initial  portion of the string 
		to their return type of long or long long.
	RETURN VALUE
		The converted value or 0 on error.
*/
