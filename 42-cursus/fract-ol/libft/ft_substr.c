/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:38:50 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:45:42 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		l_s;
	size_t		real_l;

	if (!s)
		return (NULL);
	l_s = ft_strlen(s);
	if (l_s <= start)
		real_l = 0;
	else if (len <= l_s - start)
		real_l = len;
	else
		real_l = l_s - start;
	substr = (char *)malloc(real_l + 1);
	if (!substr)
		return (NULL);
	s = s + start;
	if (start < l_s)
		ft_strlcpy(substr, s, real_l + 1);
	else
		substr[0] = '\0';
	return (substr);
}
