/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 02:31:42 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:38:01 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		l_src;

	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	i = 0;
	while (i < size - 1 && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (l_src);
}
