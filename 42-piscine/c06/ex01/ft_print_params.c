/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:54:15 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/21 17:13:30 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (j <= argc - 1)
	{
		i = 0;
		while (argv[j][i] != '\0')
			write(1, &argv[j][i++], 1);
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
