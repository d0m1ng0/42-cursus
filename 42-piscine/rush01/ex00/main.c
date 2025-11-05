/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:39:07 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 23:18:41 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_parser_input(char *str, int el_input[16]);
int		ft_backtrack(int grid[4][4], int el_input[16]);
void	ft_print_matrix(int grid[4][4]);
void	ft_print_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *s);

void	ft_init_matrix(int matrix[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	el_input[16];
	int	matrix[4][4];

	if (argc != 2)
	{
		ft_print_error();
		return (1);
	}
	if (!ft_parser_input(argv[1], el_input))
	{
		ft_print_error();
		return (1);
	}
	ft_init_matrix(matrix);
	if (!ft_backtrack(matrix, el_input))
	{
		ft_print_error();
		return (1);
	}
	ft_print_matrix(matrix);
	return (0);
}
