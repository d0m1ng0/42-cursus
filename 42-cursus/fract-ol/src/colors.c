/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 07:58:22 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 15:19:50 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	frt_color(int iteration, t_fractol *f)
{
	int	r;
	int	g;
	int	b;

	if (iteration == f->max_iteration)
		return (0x000000);
	r = (iteration * 9 + f->color_shift) % 256;
	g = (iteration * 5 + f->color_shift * 2) % 256;
	b = (iteration * 13 + f->color_shift * 3) % 256;
	return ((r << 16) | (g << 8) | b);
}
