/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:52:06 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:45:01 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && (i < len))
	{
		if (i > len - len_little)
			return (NULL);
		j = 0;
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
