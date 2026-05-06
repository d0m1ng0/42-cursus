/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:08:32 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:40:41 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_tmp;
	unsigned const char	*src_tmp;

	if (dest == src)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned const char *)src;
	while (n-- > 0)
	{
		*dest_tmp++ = *src_tmp++;
	}
	return (dest);
}
