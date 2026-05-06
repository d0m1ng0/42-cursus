/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:28:28 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:45:19 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s);
	s = s + l;
	while (l > 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		l--;
		s--;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
