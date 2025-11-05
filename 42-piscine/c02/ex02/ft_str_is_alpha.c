/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:18:11 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/16 23:33:22 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(('A' <= str[i] && str[i] <= 'Z')
				|| ('a' <= str[i] && str[i] <= 'z')))
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
	char *str_alpha = "string";
	char *str_num = "st41ng";
	char *str_empty = "";
	
	printf("it is a string : %d\n",ft_str_is_alpha(str_alpha));
	printf("it is NOT a string : %d\n",ft_str_is_alpha(str_num));
	printf("it is empty : %d\n",ft_str_is_alpha(str_empty));
	return (0);
}
*/
