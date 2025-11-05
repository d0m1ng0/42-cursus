/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:12:23 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/20 22:49:22 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nbr)
{
	if (nbr < 0)
	{
		return (0);
	}
	else if (nbr == 1 || nbr == 0)
		return (1);
	else
		return (nbr * ft_recursive_factorial(nbr - 1));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_str_to_i(char *str)
{
	int	str_to_i;
	int	i;

	i = 0;
	str_to_i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
	//	if (str_to_i > 2147483647)
	//		return (0);
		str_to_i = str_to_i * 10 + (str[i] - '0');
		i++;
	}
	return (str_to_i);

}

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
	nbr = atoi(argv[1]);
	if (nbr < 0 || (('a' <= argv[1][0]) && (argv[1][0] <= 'z')))
		write(1, "what the f.ck??\n", 17);
	else
		printf("the factorial of nbr is = \n %i", ft_recursive_factorial(nbr));
	}
	return(0);
}
*/
