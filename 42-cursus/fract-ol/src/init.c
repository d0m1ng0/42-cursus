/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:22:14 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 20:14:46 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frt_init_data(t_fractol *f)
{
	f->mlx = NULL;
	f->window = NULL;
	f->image.ptr = NULL;
	f->image.addr = NULL;
	f->image.bpp = 0;
	f->image.line_len = 0;
	f->image.endian = 0;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iteration = 80;
	f->type = MANDELBROT;
	f->julia_x = -0.8;
	f->julia_y = 0.156;
	f->julia_mouse = 0;
	f->color_shift = 0;
}

int	frt_init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->window)
		return (0);
	return (1);
}

int	frt_init_image(t_fractol *f)
{
	f->image.ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image.ptr)
		return (0);
	f->image.addr = mlx_get_data_addr(f->image.ptr, &f->image.bpp,
			&f->image.line_len, &f->image.endian);
	if (!f->image.addr)
		return (0);
	return (1);
}
