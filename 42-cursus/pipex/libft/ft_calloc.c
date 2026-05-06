/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:53:01 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:35:54 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_alloc;

	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	mem_alloc = (void *)malloc(nmemb * size);
	if (mem_alloc == NULL)
		return (NULL);
	ft_bzero(mem_alloc, nmemb * size);
	return (mem_alloc);
}
