/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:29:34 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/12 14:58:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str++)
	{
		write(1, &str, 1);
	}
}
/*
int	main(void)
{
	char *str;

	str = "ciao";
	printf("%s", str);
		
}
*/
