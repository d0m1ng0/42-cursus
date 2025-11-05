/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbabot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:38:10 by dbabot            #+#    #+#             */
/*   Updated: 2025/08/10 23:06:33 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_str_to_i(char *str)
{
	int	str_to_i;
	int	i;

	i = 0;
	str_to_i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		str_to_i = str_to_i * 10 + (str[i] - '0');
		i++;
		if (str_to_i > 2147483647)
			return (0);
	}
	return (str_to_i);
}

void	rush(int x, int y);

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	while (argc == 3)
	{
		x = ft_str_to_i(argv[1]);
		y = ft_str_to_i(argv[2]);
		if (x <= 0 || y <= 0)
		{
		}
		else
		{
			rush(x, y);
		}
		return (0);
	}
}
