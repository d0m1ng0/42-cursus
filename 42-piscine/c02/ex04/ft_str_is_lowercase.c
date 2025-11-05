/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:35:37 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 00:00:46 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
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
	char *str1 = "abcdeF";
	char *str2 = "string";
	char *str3 = "";

	printf("there are NOT only lowercase : %d\n", ft_str_is_lowercase(str1));
	printf("there are only lowercase : %d\n", ft_str_is_lowercase(str2));
	printf("it is empty : %d", ft_str_is_lowercase(str3));
	return (0);
}
*/
