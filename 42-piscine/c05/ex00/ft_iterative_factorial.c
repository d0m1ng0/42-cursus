/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:45:32 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/20 22:50:46 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nbr)
{
	int	flag;
	int	fac_nbr;

	if (nbr < 0)
		return (0);
	else if (nbr == 0 || nbr == 1)
		return (1);
	else
	{
		fac_nbr = nbr;
		flag = nbr - 1;
		while (flag > 0)
		{	
			fac_nbr = fac_nbr * (flag);
			flag--;
		}
		return (fac_nbr);
	}
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
	nbr = ft_str_to_i(argv[1]);
	if (nbr < 0 || !(('0' <= argv[1][0]) && (argv[1][0] <= '9')))
		write(1, "what the f.ck?\n", 14);
	else
		printf("the factorial of nbr is = \n %i", ft_iterative_factorial(nbr));
	}
	return(0);
}
*/
