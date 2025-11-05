/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:51:06 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 23:17:56 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parser_input(char *str, int el_input[16])

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{		
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (0);
		el_input[j++] = str[i] - '0';
		i++;
		if (j < 16)
		{
			if (!(str[i] == ' '))
				return (0);
			i++;
		}
	}
	return (str[i] == '\0');
}
