/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:12:50 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/01 07:37:26 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	flags_negative_or_zero(long *n_l, size_t *len, size_t *flag)
{
	*len = 1;
	if (*n_l < 0)
	{
		*flag = 1;
		*n_l = -*n_l;
	}
}

static void	len_counting(long *n_l, size_t *len)
{
	long	n_l_backup;

	n_l_backup = *n_l;
	while (n_l_backup > 0)
	{
		n_l_backup = n_l_backup / 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	char	*n_ch;
	size_t	len;
	long	n_l;
	size_t	flag;

	n_l = n;
	len = 0;
	flag = 0;
	if (n_l <= 0)
		flags_negative_or_zero(&n_l, &len, &flag);
	len_counting (&n_l, &len);
	n_ch = (char *)malloc(len + 1);
	if (!n_ch)
		return (NULL);
	n_ch[len] = '\0';
	while (len > flag)
	{
		n_ch[len - 1] = n_l % 10 + '0';
		n_l = n_l / 10;
		len--;
	}
	if (flag)
		n_ch[0] = '-';
	return (n_ch);
}
