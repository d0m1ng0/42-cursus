/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:11:30 by dverdini          #+#    #+#             */
/*   Updated: 2026/03/31 18:56:41 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
/*
** ------------------- headers -------------------------------------------------
*/
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdint.h>
/*
** ------------------- ft00 - counting and printing -----=----------------------
*/			
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
/*
** ------------------- ft01 - ctype and characters -----------------------------
*/			
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
/*
** ------------------- ft02 - string manipulation ------------------------------
*/			
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*
** ------------------- ft04 - allocation and duplication -----------------------
*/			
char	*ft_strdup(const char *s);
/*
** ------------------- ft05 - manipulation and convertion ----------------------
*/	
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
#endif
