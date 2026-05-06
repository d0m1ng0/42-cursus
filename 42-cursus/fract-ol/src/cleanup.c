/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:57:56 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/03 19:31:52 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frt_cleanup(t_fractol *f)
{
	if (f->image.ptr)
	{
		mlx_destroy_image(f->mlx, f->image.ptr);
		f->image.ptr = NULL;
	}
	if (f->window)
	{
		mlx_destroy_window(f->mlx, f->window);
		f->window = NULL;
	}
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		f->mlx = NULL;
	}
}

int	frt_close(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	frt_cleanup(f);
	exit(0);
	return (0);
}
