/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:50:59 by cn-goie           #+#    #+#             */
/*   Updated: 2025/08/23 12:41:43 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_HEADER_H
# define FT_DICT_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_utils.h"
# include "charnum.h"
# include "t_nbr_str.h"
# include "file_to_buf.h"
# include "dict_parse.h"
# include "charnum_write.h"

/* UTILS */

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		dict_error(void);
#endif
