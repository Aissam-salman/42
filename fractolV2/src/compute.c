/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:37:51 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/22 15:33:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	out;

	out.x = z.x + c.x;
	out.y = z.y + c.y;
	return (out);
}

t_complex	square_complex(t_complex z)
{
	t_complex	tmp;

	tmp.x = (z.x * z.x) - (z.y * z.y);
	tmp.y = 2 * z.x * z.y;
	return (tmp);
}

void	choice_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_cordinate(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;
	int				color;
	double			iter;

	z.x = (scale_between(x, -2, 2, WIDTH) * fractal->zoom) + fractal->offset_x;
	z.y = (scale_between(y, 2, -2, HEIGHT) * fractal->zoom) +fractal->offset_y;
	choice_set(&z, &c, fractal);
	i = 0;
	iter = 0;
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->limits)
		{
			iter = smooth_color(z, i);
			color = get_color(iter, fractal);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, fractal->color1);
}

void	compute(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_cordinate(x, y, fractal);
			x++;
		}
		y++;
	}
}
