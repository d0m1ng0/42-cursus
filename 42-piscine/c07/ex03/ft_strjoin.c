/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:17:47 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/28 17:01:33 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_len_tot(int size, char **strs, char *sep)
{
	int	i;
	int	len_tot;
	int	len_sep;

	len_sep = ft_strlen(sep);
	len_tot = 0;
	i = 0;
	while (i < size)
	{
		len_tot = len_tot + ft_strlen(strs[i]);
		i++;
	}
	len_tot = len_tot + len_sep * (size - 1);
	return (len_tot);
}

void	ft_strcat_strs_sep(char *strj, char **strs, char *sep, int size )
{
	int	s;
	int	j;
	int	e;

	s = 0;
	j = 0;
	while (s < size)
	{
		e = 0;
		while (strs[s][e] != '\0')
			strj[j++] = strs[s][e++];
		if (s < size - 1)
		{
			e = 0;
			while (sep[e] != '\0')
				strj[j++] = sep[e++];
		}
		s++;
	}
	strj[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strj;
	int		len_tot;

	if (size == 0)
	{
		strj = (char *)malloc(sizeof(char) * (1));
		if (strj == NULL)
			return (NULL);
		strj[0] = '\0';
		return (strj);
	}
	len_tot = ft_len_tot(size, strs, sep);
	strj = (char *)malloc(sizeof(char) * (len_tot + 1));
	if (strj == NULL)
		return (NULL);
	ft_strcat_strs_sep(strj, strs, sep, size);
	return (strj);
}
/*
int	main(void)
{
	char	*sep = " ";
	char	*strs[] = {"hello", "world!", "I", "love", "coding."};
	int		size;
	char	*strjoined;

	size = 5;
	strjoined = ft_strjoin(size, strs, sep);
	printf("%s\n", strjoined);
	free (strjoined);
	return (0);
}
*/
