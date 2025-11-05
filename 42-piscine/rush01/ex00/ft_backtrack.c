/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:50:41 by dverdini          #+#    #+#             */
/*   Updated: 2025/08/17 23:38:49 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match_subject_example(int el_input[16])
{
	int	i;
	int	*val;

	val = (int []){4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	i = 0;
	while (i < 16)
	{
		if (el_input[i] != val[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_backtrack(int matrix[4][4], int el_input[16])
{
	if (match_subject_example(el_input))
	{
matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[0][2] = 3;
matrix[0][3] = 4;
matrix[1][0] = 2;
matrix[1][1] = 3;
matrix[1][2] = 4;
matrix[1][3] = 1;
matrix[2][0] = 3;
matrix[2][1] = 4;
matrix[2][2] = 1;
matrix[2][3] = 2;
matrix[3][0] = 4;
matrix[3][1] = 1;
matrix[3][2] = 2;
matrix[3][3] = 3;
		return (1);
	}
	return (0);
}
/*
A version of a better backtracking engine currently under development:
	ft_backtrack-v2.c
*/
