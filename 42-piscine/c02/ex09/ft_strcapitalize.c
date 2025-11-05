/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:03:07 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/15 14:24:16 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_alpha_numeric(char str)
{
	if (('A' <= str && str <= 'Z')
		|| ('a' <= str && str <= 'z')
		|| ('0' <= str && str <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word_detector;

	i = 0;
	new_word_detector = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alpha_numeric(str[i]))
		{
			if (new_word_detector && ('a' <= str[i] && str[i] <= 'z'))
			{	
				str[i] = str[i] - 32;
			}
			else if (!new_word_detector && ('A' <= str[i] && str[i] <= 'Z'))
			{
				str[i] = str[i] + 32;
			}	
			new_word_detector = 0;
		}
		else
			new_word_detector = 1;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char *str_capitalized = ft_strcapitalize(str);
	printf("Ecco la strcapitalizzazione : %s\n", str);	
	return (0);
}
*/
