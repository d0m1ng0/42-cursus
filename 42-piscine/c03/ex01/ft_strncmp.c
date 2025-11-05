/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:48:17 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/19 04:31:56 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main (void)
{
	char *s1 = "42";
	char *s2 = "42";
	char *s_empty = "";

	//printing the return value of the strncmp()
	printf("normal strncmp of s1, s2 : %d\n", strncmp(s1, s2, 2));	
	printf("42 nstr-comparison of s1, s2 : %d\n", ft_strncmp(s1, s2, 2));	
	printf("42 nstr-comparison of s1, s_empty : %d\n", ft_strncmp(s1, s_empty, 2));	

	return (0);
}
*/
