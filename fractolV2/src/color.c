/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 15:09:04 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int lerp_color(int color1, int color2, double ratio)
{
	t_color_rgb co1;
	t_color_rgb co2;
	t_color_rgb final;

	co1.r = color1 >> 16 & 0xFF;
	co1.g = color1 >> 8 & 0xFF;
	co1.b = color1 & 0xFF;
	co2.r = color2 >> 16 & 0xFF;
	co2.g = color2 >> 8 & 0xFF;
	co2.b = color2 & 0xFF;
	final.r = (1 - ratio) * co1.r + ratio * co2.r;
	final.g = (1 - ratio) * co1.g + ratio * co2.g;
	final.b = (1 - ratio) * co1.b + ratio * co2.b;
	return (final.r << 16 | final.g << 8 | final.b);
}

double	smooth_color(t_complex z, int i)
{
	double	iter;
	double	log_zn;
	double	nu;

	log_zn = log(z.x * z.x + z.y * z.y) / 2;
	nu = log(log_zn / log(2)) / log(2);
	iter = i + 1 - nu;
	return (iter);
}

void	generate_palette(t_fractal *fractal)
{
	unsigned short		i;
	unsigned short seg;

	fractal->palette = malloc(sizeof(int) * (NB_ITER + 1));
	if (!fractal->palette)
		error_malloc();
	ft_bzero(fractal->palette, NB_ITER);
	i = 0;
	seg = floor(NB_ITER / 3);
	while (i < NB_ITER )
	{
		if (i < seg)
			fractal->palette[i] = lerp_color(fractal->color1, fractal->color2,
									(double) i / seg);
		else if (i < seg * 2)
			fractal->palette[i] = lerp_color(fractal->color1, fractal->color2,
									(double)(i - seg) / seg);
		else 
			fractal->palette[i] = lerp_color(fractal->color1, fractal->color2,
									(double)(i - 2 * seg) / seg);
		i++;
	}
	fractal->palette[NB_ITER - 1] = 0x000000;
}

int	get_color(int i, t_fractal *fractal)
{
	// if (i < 0)
	// 	i = 0;
	// if (i > NB_ITER)
	// 	i = NB_ITER - 1;
	return (fractal->palette[i]);
}
