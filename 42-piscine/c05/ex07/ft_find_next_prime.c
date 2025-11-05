/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:01:30 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/21 02:25:44 by dverdini         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb <= 3)
		return (3);
	while (nb % 2 == 0)
		nb = nb + 1;
	while (!ft_is_prime(nb))
		nb = nb + 2;
	return (nb);
}
/*
#include <stdio.h>
int	main()
{
	int	nb;

	nb = 24;
	printf("the next prime is : %d\n", ft_find_next_prime(nb));
	return (0);
}
*/
