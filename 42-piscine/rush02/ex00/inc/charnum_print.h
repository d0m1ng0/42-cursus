/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnum_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:42:50 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/24 17:42:52 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARNUM_PRINT_H
# define CHARNUM_PRINT_H

# include "t_nbr_str.h"
# include "ft_utils.h"
# include "dict_find.h"

int	print_full(t_nbr_str *dict, char *buf);
int	print_seg(t_nbr_str *dict, int seg);
int	print_unit(int *sp, t_nbr_str *dict, char unit);
int	print_nnn(int *sp, t_nbr_str *dict, char *buf);
#endif
