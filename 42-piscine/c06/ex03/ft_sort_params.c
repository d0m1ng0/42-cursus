/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:24:55 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/24 00:57:55 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i++], 1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned)s1[i] - (unsigned)s2[i]);
	}
	return ((unsigned)s1[i] - (unsigned)s2[i]);
}

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	repeat;

	repeat = 1;
	while (repeat == 1)
	{
		repeat = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap_str(&argv[i], &argv[i + 1]);
				repeat = 1;
			}
			i++;
		}
	}
	i = 1;
	while (i <= argc - 1)
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
