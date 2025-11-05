/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:56:34 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 02:17:15 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <= str[i] && str[i] <= 'Z'))
		str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "ECOLE 42";

	printf("ECOLE 42 ->  %s\n", ft_strlowcase(str));
	return (0);
}
*/
