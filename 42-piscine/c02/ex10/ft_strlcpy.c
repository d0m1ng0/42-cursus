/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:59:58 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 04:58:22 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l_src;

	i = 0;
	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (l_src);
}
/*
#include <unistd.h>
int	main(void)
{
	char dest[5];
	char *src = "hey";
	unsigned int l_src;

	l_src = ft_strlcpy(dest, src, 5);
	printf("l_src is : %d", l_src);
	return (0);
}
*/
