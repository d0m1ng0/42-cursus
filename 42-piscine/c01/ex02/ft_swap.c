/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:26:45 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/12 14:27:29 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	*ptr_a;
	int	*ptr_b;

	a = 14;
	b = 41;
	ptr_a = &a;		
	ptr_b = &b;
	ft_swap(*ptr_a, *ptr_ b);
	printf("il numero modificato e %i", a);
	printf("il numero modificato e %i", b);
	return (0);
}
*/
