/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:06:20 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/13 13:11:16 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
/*
int main(void)
{
	int a[5] = {1,2,3,4,5};
	int i;

	i = 0;
	ft_rev_int_tab(a, 5);
	while (i < 5)
	{
		printf("elemento %d, ", a[i]);
		i++;
	}
	return (0);
}
*/
