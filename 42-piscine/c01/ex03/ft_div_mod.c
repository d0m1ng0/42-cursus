/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:59:14 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/13 16:40:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int first;int second;int *pointer_to_div;int *pointer_to_mod;int div;int mod;

	first = 42;
	second = 13;
	//pointer_to_div=&div; //try to point to div and mod differents
				//from first and second
	//pointer_to_div=&mod;
	div = 0;
	mod = 0;
	ft_div_mod(first, second, &div, &mod);
	printf("%d\n", div);
	printf("%d", mod);
}
*/
