/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:41:33 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 18:41:35 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_FIND_H
# define DICT_FIND_H

# include <stdlib.h>
# include "t_nbr_str.h"

t_nbr_str	*dict_find(t_nbr_str *dict, char *nbr);
t_nbr_str	*dict_find_char(t_nbr_str *dict, char c);
t_nbr_str	*dict_find_seg(t_nbr_str *dict, int seg);
#endif
