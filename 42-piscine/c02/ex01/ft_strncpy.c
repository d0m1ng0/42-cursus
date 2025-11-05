/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:56:06 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 04:56:27 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char			*returned;
	unsigned int	i;

	i = 0;
	returned = dest;
	while (*src && i < n)
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest++ = '\0';
		i++;
	}
	return (returned);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char dest[10];
	char src[] = "inside";
	
	printf("%s\n", strncpy(dest, src, 3));
	return (0);
}
*/
