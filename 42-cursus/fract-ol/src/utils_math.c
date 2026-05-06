/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 07:41:17 by dverdini          #+#    #+#             */
/*   Updated: 2026/05/04 19:24:40 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	frt_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	frt_map_x(int x, t_fractol *f)
{
	double	value;

	value = ((double)x - WIDTH / 2.0);
	value = value * 4.0 / WIDTH;
	value = value / f->zoom;
	value = value + f->offset_x;
	return (value);
}

double	frt_map_y(int y, t_fractol *f)
{
	double	value;

	value = ((double)y - HEIGHT / 2.0);
	value = value * 4.0 / HEIGHT;
	value = value / f->zoom;
	value = value + f->offset_y;
	return (value);
}

int	frt_is_valid_double(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (frt_is_digit(str[i]))
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

double	frt_atod(char *str)
{
	int		i;
	double	sign;
	double	result;
	double	decimal;

	i = 0;
	sign = 1.0;
	result = 0.0;
	decimal = 0.1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (frt_is_digit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (frt_is_digit(str[i]))
	{
		result = result + (str[i++] - '0') * decimal;
		decimal *= 0.1;
	}
	return (result * sign);
}
/*
- To vertically invert the image change the sign of the scale:
 in frt_map_y change -> value = value * -4.0 / HEIGHT;
Y-axes points down. Near the mathematical conventions.
*/
