/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:46:57 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/19 04:54:21 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l_dst;
	unsigned int	l_str;
	unsigned int	i;

	l_str = ft_strlen(src);
	l_dst = 0;
	while (l_dst < size && dest[l_dst])
		l_dst++;
	if (l_dst == size)
		return (size + l_str);
	i = 0;
	while (src[i] && (i + l_dst < size - 1))
	{
		dest[l_dst + i] = src[i];
		i++;
	}
	dest[l_dst + i] = '\0';
	return (l_dst + l_str);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h> // cc -Wall -Werror -Wextra -lbsd
int	main(void)
{
	char dest[50] = "Hell";
	char src[] = "BONJOUR";
	int	l_debug;

	l_debug = strlcat(dest, src, 5);
	
	printf("dest 11 : HELLO-WORLD \nsrc 7 :BONJOUR\n final dest : %s\n ", dest);
	printf("dest 11 : HELLO-WORLD \nsrc 7 :BONJOUR\n return : %d\n ", l_debug);
	return (0);
}
*/
