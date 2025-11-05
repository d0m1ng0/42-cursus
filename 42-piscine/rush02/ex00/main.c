/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdonlon <kdonlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:45:19 by kdonlon           #+#    #+#             */
/*   Updated: 2025/08/23 11:47:56 by kdonlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_header.h"

int	parse_and_write(char *buf, t_nbr_str *dict, t_charnum *cn)
{
	if (parse_buf_to_dict(buf, dict) == 0)
	{
		dict_error();
		return (0);
	}
	charnum_write(cn, dict);
	return (0);
}

int	exec(char *find_nbr, char *path)
{
	t_charnum	cn;
	t_nbr_str	*dict;
	char		*buf;

	if (charnum_init(&cn, find_nbr) == 0)
		return (dict_error());
	dict = dict_create();
	if (dict == NULL)
		return (dict_error());
	buf = file_to_buf(path);
	if (buf == NULL)
	{
		dict_release(dict);
		return (dict_error());
	}
	parse_and_write(buf, dict, &cn);
	if (dict)
		dict_release(dict);
	if (buf)
		free(buf);
	return (0);
}

int	main(int argc, char **argv)
{
	char		def_path[4096];
	char		*find_nbr;
	char		*path;

	ft_strcpy(def_path, "dict/numbers.dict");
	path = def_path;
	if (argc == 2)
	{
		find_nbr = argv[1];
	}
	else if (argc == 3)
	{
		path = argv[1];
		find_nbr = argv[2];
	}
	else
		return (dict_error());
	return (exec(find_nbr, path));
}
