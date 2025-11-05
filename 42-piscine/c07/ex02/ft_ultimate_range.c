/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:10:11 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/28 17:12:38 by dverdini         ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int a, int b)
{
	int	*ultimate_range;
	int	l;

	l = b - a;
	if (l <= 0)
	{
		range = NULL;
		return (0);
	}
	ultimate_range = ft_range(a, b);
	if (ultimate_range == NULL)
		return (-1);
	*range = ultimate_range;
	return (l);
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
		interval = b - a;
		if (interval <= 0)
			return(write(1, "Error\n", 6));
		interval = ft_ultimate_range(&range, a, b);
		i = 0;
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
