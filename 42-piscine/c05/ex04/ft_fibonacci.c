/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:08:41 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/22 02:08:19 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("series at index is : # %d\n", ft_fibonacci(0));
	printf("series at index is : # %d\n", ft_fibonacci(1));
	printf("series at index is : # %d\n", ft_fibonacci(2));
	printf("series at index is : # %d\n", ft_fibonacci(3));
	printf("series at index is : # %d\n", ft_fibonacci(4));
	printf("series at index is : # %d\n", ft_fibonacci(5));
	printf("series at index is : # %d\n", ft_fibonacci(6));
	printf("series at index is : # %d\n", ft_fibonacci(7));
	printf("series at index is : # %d\n", ft_fibonacci(8));
	return (0);
}
*/
