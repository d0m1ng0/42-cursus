/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 03:50:45 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/28 21:39:52 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_only_comb(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (!(c1 == '7' && c2 == '8' && c3 == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				ft_only_comb(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
