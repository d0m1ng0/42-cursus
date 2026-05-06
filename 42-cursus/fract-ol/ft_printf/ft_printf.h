/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:21:45 by dverdini          #+#    #+#             */
/*   Updated: 2026/02/23 15:08:08 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_printf_data
{
	int	l_t;
}	t_printf_data;

/*# include <...> //per va_list
...		//per write
...		//per malloc and free
*/

int		ft_printf(const char *format, ...);
int		ft_putchar_fdl(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_putstr_fdlsec(char *s, int fd);
int		ft_putnbr_fdl(int n, int fd);
int		ft_putuint_fdl(unsigned int n, int fd);
int		ft_puthex_fdl(unsigned int n, char type, int fd);
int		ft_putptr_fdl(unsigned long n, int fd);
#endif
