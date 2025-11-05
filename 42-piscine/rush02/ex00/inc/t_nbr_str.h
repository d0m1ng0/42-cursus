/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_nbr_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:22:14 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 16:22:16 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NBR_STR_H
# define T_NBR_STR_H

# include <stdlib.h>
# include <ft_utils.h>

struct s_nbr_str
{
	char				*nbr;
	char				*str;
	struct s_nbr_str	*next;
	struct s_nbr_str	*prev;
};

typedef struct s_nbr_str	t_nbr_str;

t_nbr_str	*dict_create(void);
void		dict_release(t_nbr_str *dict);
int			dict_add_next(t_nbr_str *dict);
void		dict_print(t_nbr_str *dict);
void		dict_print_all(t_nbr_str *dict);
#endif
