/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:39:29 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 01:41:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char *str1 = "ABCDEF";
	char *str2 = "ABCDEf";
	char *str3 = ""; 

	printf("there are only UPPERCASE : %d\n", ft_str_is_uppercase(str1));
	printf("there are NOT only upercase : %d\n", ft_str_is_uppercase(str2));
	printf("it is empty %d", ft_str_is_uppercase(str3));
	return (0);
}
*/
