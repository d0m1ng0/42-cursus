/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:23:34 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 20:27:12 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frt_put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = f->image.addr + (y * f->image.line_len)
		+ (x * (f->image.bpp / 8));
	*(unsigned int *)pixel = color;
}

void	frt_render(t_fractol *f)
{
	int		x;
	int		y;
	int		iteration;
	double	cx;
	double	cy;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = frt_map_x(x, f);
			cy = frt_map_y(y, f);
			iteration = frt_get_iterations(f, cx, cy);
			frt_put_pixel(f, x, y, frt_color(iteration, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image.ptr, 0, 0);
}
/*
color = ((x * 255 / WIDTH) << 16)
	| ((y * 255 / HEIGHT) << 8);
 */
/*
void	frt_render_test(t_fractol *f)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = (x * 255 / WIDTH) << 16;
			color += (y * 255 / HEIGHT) << 8;
			frt_put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image.ptr, 0, 0);
}
*/
