/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:30:57 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/16 22:32:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	pos_char;

	pos_char = 0;
	while (src[pos_char] != '\0')
	{
		dest[pos_char] = src[pos_char];
		pos_char++;
	}
	dest[pos_char] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char dst[42];
	char src[] =  "42 school. Piscine of August";
	
	printf("Copia fatta.\n dst : \"%s\"", ft_strcpy(dst, src));
	return (0);
}
*/
