/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:54:51 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:37:48 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l_s;
	char	*s_copy;
	char	*start;

	l_s = ft_strlen(s);
	s_copy = (char *)malloc(l_s + 1);
	if (s_copy == NULL)
		return (NULL);
	start = s_copy;
	while (*s)
	{
		*s_copy++ = *s++;
	}
	*s_copy = '\0';
	return (start);
}
