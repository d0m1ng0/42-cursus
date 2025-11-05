/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:42:23 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 01:57:12 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((' ' > str[i] || str[i] > '~'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *str1 = "a1~";
	char *str2 = "a\t";
	char *str3 = ""; 

	printf("it is has only printable chars : %d\n", ft_str_is_printable(str1));
	printf("it is not printable : %d\n", ft_str_is_printable(str2));
	printf("it is empty : %d", ft_str_is_printable(str3));
	return (0);
}
*/
