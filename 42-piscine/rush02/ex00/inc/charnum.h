/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charnum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:28:19 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 20:28:22 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARNUM_H
# define CHARNUM_H

# include "char_funcs.h"

struct s_charnum
{
	char	*buf;
	int		len;
	int		nseg;
};
typedef struct s_charnum	t_charnum;

int	is_seg(char *buf);
int	charnum_init(t_charnum *cn, char *num);
int	charnum_get_seg(t_charnum *cn, int seg, char buf[4]);
int	buf_zero(char *buf);
#endif
