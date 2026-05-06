/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:27:07 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 13:37:35 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **str_spl, size_t w_to_free)
{
	size_t	i;

	i = 0;
	while (i < w_to_free)
	{
		free(str_spl[i]);
		i++;
	}
	free(str_spl);
}

static size_t	count_words(char const *s, char c)
{
	size_t	new_w;
	size_t	counter;
	size_t	i;

	new_w = 0;
	counter = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && new_w == 0)
		{
			new_w = 1;
			counter++;
		}
		else if (s[i] == c && new_w == 1)
			new_w = 0;
		i++;
	}
	return (counter);
}

static char	*get_and_stock(char const *s, char c, size_t *gps)
{
	char	*word;
	size_t	start;
	size_t	len;

	start = 0;
	len = 0;
	while (s[*gps] != '\0' && s[*gps] == c)
		(*gps)++;
	if (s[*gps] != c)
		start = *gps;
	while (s[*gps] != '\0' && s[*gps] != c)
		(*gps)++;
	len = *gps - start;
	word = ft_substr(s, (unsigned int)start, len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**str_spl;
	size_t		w_to_alloc;
	size_t		j;
	size_t		gps;

	if (!s)
		return (NULL);
	w_to_alloc = count_words(s, c);
	str_spl = (char **)malloc((w_to_alloc + 1) * sizeof(char *));
	if (!str_spl)
		return (NULL);
	j = 0;
	gps = 0;
	while (j < w_to_alloc && s[gps] != '\0')
	{
		str_spl[j] = get_and_stock(s, c, &gps);
		if (!str_spl[j])
		{
			free_all(str_spl, j);
			return (NULL);
		}
		j++;
	}
	str_spl[j] = NULL;
	return (str_spl);
}
