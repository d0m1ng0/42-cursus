/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:17:00 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/21 17:31:00 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	a;
	int	e;

	a = argc - 1;
	while (a > 0)
	{
		e = 0;
		while (argv[a][e] != '\0')
		{
			write(1, &argv[a][e], 1);
			e++;
		}
		a--;
		write(1, "\n", 1);
	}
	return (0);
}
