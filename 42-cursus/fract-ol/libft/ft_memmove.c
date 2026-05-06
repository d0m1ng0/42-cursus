/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:38:08 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:40:51 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (s < d)
	{
		d = d + n;
		s = s + n;
		while (n-- > 0)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
