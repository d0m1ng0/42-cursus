/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:54:51 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 20:19:38 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	frt_start(t_fractol *f, int argc, char **argv)
{
	frt_init_data(f);
	if (!frt_parse_args(argc, argv, f))
	{
		frt_usage_msg();
		return (0);
	}
	if (!frt_init_mlx(f))
		return (0);
	if (!frt_init_image(f))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	(void)argv;
	if (!frt_start(&f, argc, argv))
	{
		frt_cleanup(&f);
		return (1);
	}
	frt_render(&f);
	mlx_key_hook(f.window, frt_key_hook, &f);
	mlx_mouse_hook(f.window, frt_mouse_hook, &f);
	mlx_hook(f.window, EVENT_MOUSE_MOVE, MASK_MOUSE_MOVE,
		(void *)frt_mouse_move, &f);
	mlx_hook(f.window, 17, 0, (void *)frt_close, &f);
	mlx_loop(f.mlx);
	frt_cleanup(&f);
	return (0);
}
