/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:07:43 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 13:07:47 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADER PROTECTION
#ifndef DICT_PARSE_H
# define DICT_PARSE_H

# include <stdlib.h>
# include "t_nbr_str.h"
# include "char_funcs.h"

int	parse_buf_to_dict(char *buf, t_nbr_str *dict);
#endif
