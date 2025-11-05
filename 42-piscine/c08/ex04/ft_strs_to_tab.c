/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 02:32:31 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/28 04:05:13 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*dup;

	l = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_free_stock_str(struct s_stock_str *stock_str)
{
	int	i;

	if (!stock_str)
		return ;
	i = 0;
	while (stock_str[i].copy != NULL)
		free(stock_str[i++].copy);
	free(stock_str);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	struct s_stock_str	*arr;
	int					i;

	arr = malloc(sizeof(struct s_stock_str) * (argc + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		arr[i].size = ft_strlen(argv[i]);
		arr[i].str = argv[i];
		arr[i].copy = ft_strdup(argv[i]);
		if (arr[i].copy == NULL)
		{
			ft_free_stock_str(arr);
			return (NULL);
		}
		i++;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stock_str	*arr;
	
	arr = ft_strs_to_tab(argc, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("str: %s, ",arr[i].str);
		printf("size: %d, ", arr[i].size);
		printf("copy: %s.\n", arr[i].copy);
	}
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
#endif
*/
