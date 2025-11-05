/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:43:31 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/18 20:25:58 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned)s1[i] - (unsigned)s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *s1 = "42";
	char *s2 = "42";
	char *s_empty = "";

	//printing the return value of the strcmp()
	printf("normal strcmp of s1, s2 : %d\n", strcmp(s1, s2));
	printf("42 str-comparison of s1, s2: %d\n", ft_strcmp(s1, s2));
	printf("42 str-comparison of "" and s2 : %d\n", ft_strcmp(s_empty, s2));

	return (0);
}
*/
