/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:01:53 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 16:24:40 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frt_usage_msg(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <real> <imaginary>\n", 38);
	write(1, "  ./fractol burning_ship\n", 25);
}

static int	frt_parse_mandelbrot(int argc, t_fractol *f)
{
	if (argc != 2)
		return (0);
	f->type = MANDELBROT;
	return (1);
}

static int	frt_parse_julia(int argc, char **argv, t_fractol *f)
{
	if (argc != 4)
		return (0);
	if (!frt_is_valid_double(argv[2])
		|| !frt_is_valid_double(argv[3]))
		return (0);
	f->type = JULIA;
	f->julia_x = frt_atod(argv[2]);
	f->julia_y = frt_atod(argv[3]);
	f->julia_mouse = 1;
	return (1);
}

static int	frt_parse_burning_ship(int argc, t_fractol *f)
{
	if (argc != 2)
		return (0);
	f->type = BURNING_SHIP;
	f->zoom = 0.75;
	f->offset_x = -0.45;
	f->offset_y = -0.55;
	return (1);
}

int	frt_parse_args(int argc, char **argv, t_fractol *f)
{
	if (argc < 2)
		return (0);
	if (frt_str_are_eq(argv[1], "mandelbrot"))
		return (frt_parse_mandelbrot(argc, f));
	if (frt_str_are_eq(argv[1], "julia"))
		return (frt_parse_julia(argc, argv, f));
	if (frt_str_are_eq(argv[1], "burning_ship"))
		return (frt_parse_burning_ship(argc, f));
	return (0);
}
