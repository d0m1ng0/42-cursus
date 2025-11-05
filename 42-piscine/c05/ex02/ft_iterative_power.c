/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:44:16 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/22 14:23:43 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		result = 1;
		while (power > 0)
		{
			result = result * nb;
			power--;
		}
		return (result);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	printf("risultato : %d\n", ft_iterative_power(-2, -1));
	printf("risultato : %d\n", ft_iterative_power(-2, 0));
	printf("risultato : %d\n", ft_iterative_power(-2, 1));
	printf("risultato : %d\n", ft_iterative_power(-2, 2));
	printf("risultato : %d\n", ft_iterative_power(-2, 3));
	printf("risultato : %d\n", ft_iterative_power(-2, 4));
	printf("risultato : %d\n", ft_iterative_power(-2, 5));
	printf("risultato : %d\n", ft_iterative_power(-2, 6));
	return (0);
}
*/
