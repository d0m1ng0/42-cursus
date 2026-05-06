/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:12:44 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:43:25 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		l_dst;
	size_t		l_src;

	i = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return ((l_src + size));
	dst = dst + l_dst;
	while (i < size - l_dst - 1 && *src)
	{
		*(dst)++ = *src++;
		i++;
	}
	*dst = '\0';
	return (l_src + l_dst);
}
