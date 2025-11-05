/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:40:35 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/21 02:00:55 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("yes = 1, no = 0 : %d\n", ft_is_prime(23));
	return (0);
}
*/
