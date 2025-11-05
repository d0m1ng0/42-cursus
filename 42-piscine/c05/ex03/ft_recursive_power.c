/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:16:40 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/21 02:44:04 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * (ft_recursive_power(nb, power - 1)));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_power(4, 3));
	return (0);
}
*/
