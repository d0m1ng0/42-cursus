/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:40:51 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/17 17:55:24 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	if (s)
	{
		l = ft_strlen(s);
		write(fd, s, l);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_l;

	n_l = n;
	if (n_l < 0)
	{
		n_l = -n_l;
		ft_putchar_fd('-', fd);
	}
	if (n_l >= 10)
	{
		ft_putnbr_fd(n_l / 10, fd);
	}
	ft_putchar_fd(n_l % 10 + '0', fd);
}

int	main(void)
{
	int		fd;
	char	*line;

	ft_putstr_fd("========TEST 1: ERROR========\n", 1);
	fd = -1;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd(line ? line : "Error in the file opening.\n", 1);
		ft_putstr_fd("line is NULL.\n", 1);
	}
/*	ft_putstr_fd("========TEST 2: EMPTY========\n", 1);
	fd = open("tests_folder/test_empty.txt", O_RDONLY);
	ft_putstr_fd("========TEST 3: LONG========\n", 1);
	fd = open("tests_folder/test_long.txt", O_RDONLY);
	ft_putstr_fd("========TEST 4: NO NEWLINE========\n", 1);
	fd = open("tests_folder/test_no_newline.txt", O_RDONLY);
	ft_putstr_fd("========TEST 5: NO ONE LINE========\n", 1);
	fd = open("tests_folder/test_one_line.txt", O_RDONLY);
	ft_putstr_fd("========TEST 6: 1 CHAR========\n", 1);
	fd = open("tests_folder/test_1char.txt", O_RDONLY);
	ft_putstr_fd("========TEST 7: TEST========\n", 1);
	fd = open("tests_folder/test.txt", O_RDONLY);
*/

	ft_putstr_fd("======== READ FROM STDIN=====\n", 1);
	fd = 0;

	ft_putstr_fd("--- fd VALE: ", 1);
	ft_putnbr_fd(fd, 1);
	ft_putstr_fd("\n--- INIZIO LETTURA ---\n", 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(fd);
	}
	ft_putstr_fd("--- FINE LETTURA ---\n", 1);
	close(fd);
	fd = 0;
	return (0);
}
