/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:33:55 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 11:34:23 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TO_BUF_H
# define FILE_TO_BUF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*file_to_buf(const char *path);
#endif
