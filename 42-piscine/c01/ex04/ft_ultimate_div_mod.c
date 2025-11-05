/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:55:17 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/13 16:47:52 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}
/*
int	main(void)
{
	int first;
	int second;
	int *pointer_to_first;
	int *pointer_to_second;

	first = 42;
	second = 13;
	pointer_to_first=&first;
	pointer_to_second=&second;

	ft_ultimate_div_mod(pointer_to_first, pointer_to_second);
	printf("%d", first);
	printf("%d", second);
		
}
*/
