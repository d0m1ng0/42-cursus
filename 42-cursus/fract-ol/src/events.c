/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:14:36 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 21:05:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	frt_color_key(int keycode, t_fractol *f)
{
	if (keycode != KEY_C)
		return (0);
	f->color_shift += 25;
	frt_render(f);
	return (1);
}

static int	frt_move_key(int keycode, t_fractol *f)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		f->offset_x -= 0.2 / f->zoom;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		f->offset_x += 0.2 / f->zoom;
	else if (keycode == KEY_UP || keycode == KEY_W)
		f->offset_y -= 0.2 / f->zoom;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		f->offset_y += 0.2 / f->zoom;
	else
		return (0);
	frt_render(f);
	return (1);
}

int	frt_key_hook(int keycode, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keycode == KEY_ESC)
		frt_close(f);
	else if (frt_move_key(keycode, f))
		return (0);
	else if (frt_color_key(keycode, f))
		return (0);
	return (0);
}

int	frt_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;
	double		before_x;
	double		before_y;
	double		after_x;
	double		after_y;

	f = (t_fractol *)param;
	if (button != MOUSE_UP && button != MOUSE_DOWN)
		return (0);
	before_x = frt_map_x(x, f);
	before_y = frt_map_y(y, f);
	if (button == MOUSE_UP)
		f->zoom *= 1.2;
	else if (button == MOUSE_DOWN)
		f->zoom /= 1.2;
	after_x = frt_map_x(x, f);
	after_y = frt_map_y(y, f);
	f->offset_x += before_x - after_x;
	f->offset_y += before_y - after_y;
	frt_render(f);
	return (0);
}

int	frt_mouse_move(int x, int y, void *parm)
{
	t_fractol	*f;

	f = (t_fractol *)parm;
	if (f->type == JULIA && f->julia_mouse)
	{
		f->julia_x = frt_map_x(x, f);
		f->julia_y = frt_map_y(y, f);
		frt_render(f);
	}
	return (0);
}
/*
int	frt_mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (button == MOUSE_UP)
	{
		f->zoom *= 1.2;
		frt_render(f);
	}
	else if (button == MOUSE_DOWN)
	{
		f->zoom /= 1.2;
		frt_render(f);
	}
	return (0);
}
*/
