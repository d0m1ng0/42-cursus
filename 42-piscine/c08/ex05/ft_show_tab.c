/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:41:37 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/28 04:31:20 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	long	l_nbr;

	l_nbr = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		l_nbr = (-1) * nbr;
	}
	if (l_nbr >= 10)
	{
		ft_putnbr(l_nbr / 10);
	}
	ft_putchar(l_nbr % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	t_stock_str	*par;

	par = ft_strs_to_tab(argc, argv);
	ft_show_tab(par);
	return (0);
}
*/
/*
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_show_tab(struct s_stock_str *par);
struct	s_stock_str	*ft_strs_to_tab(int argc, char **argv);
#endif
*/
