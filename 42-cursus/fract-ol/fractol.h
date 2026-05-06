/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:38:24 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 20:23:17 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*----------------------------------------------------------------*/
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
/*----------------------------------------------------------------*/
# define WIDTH 800
# define HEIGHT 800

# define KEY_ESC 65307

/*----------------------------------------------------------------*/
typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef enum e_frt_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_frt_type;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_frt_type	type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		julia_x;
	double		julia_y;
	int			julia_mouse;
	int			max_iteration;
	int			color_shift;
}	t_fractol;

void	frt_init_data(t_fractol *f);
int		frt_init_mlx(t_fractol *f);
int		frt_init_image(t_fractol *f);

void	frt_cleanup(t_fractol *f);
int		frt_close(void *param);
int		frt_key_hook(int keycode, void *param);

void	frt_put_pixel(t_fractol *f, int x, int y, int color);
void	frt_render_test(t_fractol *f);

double	frt_map_x(int x, t_fractol *f);
double	frt_map_y(int y, t_fractol *f);
int		frt_mandelbrot(double cr, double ci, t_fractol *f);
int		frt_color(int iteration, t_fractol *f);
void	frt_render(t_fractol *f);

int		frt_parse_args(int argc, char **argv, t_fractol *f);
int		frt_str_are_eq(char *s1, char *s2);
void	frt_usage_msg(void);

int		frt_is_digit(char c);
int		frt_is_valid_double(char *str);
double	frt_atod(char *str);
int		frt_julia(double x, double y, t_fractol *f);
int		frt_get_iterations(t_fractol *f, double x, double y);

# define MOUSE_UP 4
# define MOUSE_DOWN 5

int		frt_mouse_hook(int button, int x, int y, void *param);

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define EVENT_MOUSE_MOVE 6
# define MASK_MOUSE_MOVE 64

int		frt_mouse_move(int x, int y, void *parm);

# define KEY_C 99

double	frt_abs(double n);
int		frt_burning_ship(double cr, double ci, t_fractol *f);

#endif
