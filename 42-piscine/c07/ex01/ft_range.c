/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:44:54 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/27 15:32:56 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	l;
	int	*range;
	int	i;

	l = max - min;
	if (l <= 0)
		return (NULL);
	range = (int *)malloc((sizeof(int)) * (l));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	*range;
	int	a;
	int	b;
	int	i;
	int	interval;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		range = ft_range(a, b);
		i = 0;
		interval = b - a;
		while (i < interval)
		{
			printf("%d\n", range[i]);
			i++;
		}
		write(1, "\n", 1);
		free (range);
	}
	return (0);
}
*/
