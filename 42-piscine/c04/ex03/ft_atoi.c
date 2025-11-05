/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:29:00 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/20 03:28:36 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13)
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	str_converted;

	i = 0;
	sign = 1;
	str_converted = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (-1) * sign;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		str_converted = str_converted * 10 + (str[i] - '0');
		i++;
	}
	return (sign * str_converted);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *str = "++--42++-424242424+++++-1";
	printf("la convesione di \"\" da : %d\n", ft_atoi(str));
	printf("la convesione di \"\" da : %d\n", atoi(str));
	return (0);
}
*/
