/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:17:36 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/17 18:57:46 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *stash)
{
	int		i;
	char	*cleaned_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	cleaned_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (cleaned_stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		l;

	l = 0;
	if (!stash || !stash[l])
		return (NULL);
	while (stash[l] && stash[l] != SEPARATOR)
		l++;
	if (stash[l] == SEPARATOR)
		l++;
	line = (char *)malloc(l + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, l + 1);
	return (line);
}

static char	*ft_create_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	package_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	package_read = 1;
	while (package_read > 0 && (!stash || !ft_strchr(stash, SEPARATOR)))
	{
		package_read = read(fd, buffer, BUFFER_SIZE);
		if (package_read == -1)
			return (free(buffer), free(stash), NULL);
		if (package_read > 0)
		{
			buffer[package_read] = '\0';
			stash = ft_strjoin_stash_buffer(stash, buffer);
			if (!stash)
				return (free(buffer), NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_create_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_clean_stash(stash);
	return (line);
}
/*
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
//	ft_putstr_fd("========TEST 2: EMPTY========\n", 1);
//	fd = open("tests_folder/test_empty.txt", O_RDONLY);
//	ft_putstr_fd("========TEST 3: LONG========\n", 1);
//	fd = open("tests_folder/test_long.txt", O_RDONLY);
//	ft_putstr_fd("========TEST 4: NO NEWLINE========\n", 1);
//	fd = open("tests_folder/test_no_newline.txt", O_RDONLY);
//	ft_putstr_fd("========TEST 5: NO ONE LINE========\n", 1);
//	fd = open("tests_folder/test_one_line.txt", O_RDONLY);
//	ft_putstr_fd("========TEST 6: 1 CHAR========\n", 1);
//	fd = open("tests_folder/test_1char.txt", O_RDONLY);
//	ft_putstr_fd("========TEST 7: TEST========\n", 1);
//	fd = open("tests_folder/test.txt", O_RDONLY);


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
*/
/*
FLOW:
1. Read and append to stash until '\n' or EOF.
2. Extract the next line from stash.
3. Clean stash by keeping only the remaing part.
*/
