/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:51:29 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 23:23:45 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_print_matrix(int matrix[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar('0' + matrix[row][col]);
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	ft_print_error(void)
{
	ft_putstr("error: invalid argument.\n");
}
