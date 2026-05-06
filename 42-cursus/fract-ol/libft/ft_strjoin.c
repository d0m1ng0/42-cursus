/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:03:23 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:43:07 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;	
	size_t	l1;
	size_t	l2;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	strjoined = malloc (l1 + l2 + 1);
	if (!strjoined)
		return (NULL);
	start = strjoined;
	while (l1-- > 0)
	{
		*strjoined++ = *s1++;
	}
	while (l2-- > 0)
	{
		*strjoined++ = *s2++;
	}
	*strjoined = '\0';
	return (start);
}
