/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:22:35 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/17 18:59:57 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*str)
	{
		str++;
	}
	return (str - start);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin_stash_buffer(char *s1, char const *s2)
{
	char	*strjoined;
	char	*start;
	char	*ptr_to_free;

	if (!s1)
	{
		s1 = malloc(1);
		if (s1)
			s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	strjoined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoined)
		return (free(s1), NULL);
	start = strjoined;
	ptr_to_free = s1;
	while (*s1)
		*strjoined++ = *s1++;
	while (*s2)
		*strjoined++ = *s2++;
	*strjoined = '\0';
	free(ptr_to_free);
	return (start);
}

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
	if (start < l_s)
	{
		s = s + start;
		ft_strlcpy(substr, s, real_l + 1);
	}
	else
		substr[0] = '\0';
	return (substr);
}
