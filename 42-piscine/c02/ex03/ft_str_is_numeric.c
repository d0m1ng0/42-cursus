/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:29:33 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/16 23:44:10 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <string.h>
#include <unistd.h>
int	main(void)
{
	char	*str1 = "123";
	char	*str2 = "st41ng";
	char	*str3 = "";

	printf("it contains only digit : %d\n", ft_str_is_numeric(str1));
	printf("NOT only digits : %d\n",ft_str_is_numeric(str2));
	printf("it is empty : %d\n", ft_str_is_numeric(str3));
	return (0);
}
*/
