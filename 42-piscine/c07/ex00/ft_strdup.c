/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:30:05 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/24 04:18:37 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hello";
	char *dup;

	dup = ft_strdup(str);
	if (dup == NULL)
		return (1);
	printf("the original : %s\n", str);
	printf("the duplicate : %s\n", dup);
	return (0);
}
*/
