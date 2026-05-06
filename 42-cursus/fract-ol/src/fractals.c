/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 07:54:44 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 20:22:09 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	frt_mandelbrot(double cr, double ci, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < f->max_iteration && zr * zr + zi * zi <= 4.0)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	frt_julia(double x, double y, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = x;
	zi = y;
	i = 0;
	while (i < f->max_iteration && zr * zr + zi * zi <= 4.0)
	{
		tmp = zr * zr - zi * zi + f->julia_x;
		zi = 2.0 * zr * zi + f->julia_y;
		zr = tmp;
		i++;
	}
	return (i);
}

int	frt_get_iterations(t_fractol *f, double x, double y)
{
	if (f->type == MANDELBROT)
		return (frt_mandelbrot(x, y, f));
	if (f->type == JULIA)
		return (frt_julia(x, y, f));
	if (f->type == BURNING_SHIP)
		return (frt_burning_ship(x, y, f));
	return (0);
}

int	frt_burning_ship(double cr, double ci, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < f->max_iteration && zr * zr + zi * zi <= 4.0)
	{
		zr = frt_abs(zr);
		zi = frt_abs(zi);
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
