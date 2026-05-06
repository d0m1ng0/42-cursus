/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:11:32 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:44:21 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_mapped;
	unsigned int	l_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	l_s = ft_strlen (s);
	str_mapped = (char *)malloc(l_s + 1);
	if (!str_mapped)
		return (NULL);
	i = 0;
	while (i < l_s)
	{
		str_mapped[i] = f(i, s[i]);
		i++;
	}
	str_mapped[i] = '\0';
	return (str_mapped);
}
