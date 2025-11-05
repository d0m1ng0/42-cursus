/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:41:03 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/19 02:02:04 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i_s;
	int	j;

	if (*to_find == '\0')
		return (str);
	i_s = 0;
	while (str[i_s] != '\0')
	{
		j = 0;
		while (to_find[j] && str[i_s + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i_s);
		i_s++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hi! hello_world!";
	char *to_find = "hello";

	printf("the result is the substr : %s\n", ft_strstr(str, to_find));
	return (0);
}
*/
