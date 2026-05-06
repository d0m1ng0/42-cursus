/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:18:14 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:41:04 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_joker;

	ptr_joker = (unsigned char *)s;
	while (n-- > 0)
	{
		*ptr_joker++ = (unsigned char)c;
	}
	return (s);
}
