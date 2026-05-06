/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:53:19 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:40:19 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned const char		*buff;

	buff = (unsigned const char *)s;
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*buff == (unsigned char)c)
			return ((void *)buff);
		buff++;
		i++;
	}
	return (NULL);
}
