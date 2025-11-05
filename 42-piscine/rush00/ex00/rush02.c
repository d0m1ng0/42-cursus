/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbabot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:38:43 by dbabot            #+#    #+#             */
/*   Updated: 2025/08/10 21:38:48 by dbabot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_top_line(int x, int y)
{
	int	mid_width;
	int	right_edge;

	mid_width = x - 2;
	right_edge = x - 1;
	ft_putchar('A');
	while (y > 0)
	{
		while (mid_width > 0)
		{
			ft_putchar('B');
			mid_width--;
		}
		while (right_edge > 0)
		{
			ft_putchar('A');
			right_edge = 0;
		}
		y = 0;
	}
	ft_putchar('\n');
}

void	ft_mid_line(int x, int y)
{
	int	mid_width;
	int	mid_height;
	int	right_edge;

	mid_width = x - 2;
	mid_height = y - 2;
	right_edge = x - 1;
	while (mid_height > 0)
	{
		ft_putchar('B');
		while (mid_width > 0)
		{
			ft_putchar(' ');
			mid_width--;
		}
		while (right_edge > 0)
		{
			ft_putchar('B');
			right_edge = 0;
		}
		mid_width = x - 2;
		right_edge = x - 1;
		mid_height--;
		ft_putchar('\n');
	}
}

void	ft_bottom_line(int x, int y)
{
	int	mid_width;
	int	mid_height;
	int	right_edge;

	right_edge = x - 1;
	mid_width = x - 2;
	mid_height = y - 1;
	while (mid_height > 0)
	{
		ft_putchar('C');
		while (mid_width > 0)
		{
			ft_putchar('B');
			mid_width--;
		}
		while (right_edge > 0)
		{
			ft_putchar('C');
			right_edge = 0;
		}
		mid_height = 0;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	ft_top_line(x, y);
	ft_mid_line(x, y);
	ft_bottom_line(x, y);
}
