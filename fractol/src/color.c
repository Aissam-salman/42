/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/17 17:31:06 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	define_color(t_fractal *fractal, double iter)
{
	int	color;

	color = (int)lerp(get_color((int)floor(iter) % NB_ITER, fractal),
			get_color((int)(floor(iter) + 1) % NB_ITER, fractal), iter
			- floor(iter));
	return (color);
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
	int		i;
	char	*hex;

	i = 0;
	fractal->palette = malloc(sizeof(int) * (NB_ITER + 1));
	if (!fractal->palette)
		error_malloc();
	ft_bzero(fractal->palette, NB_ITER);
	while (i < NB_ITER)
	{
		hex = ft_itoa_base(i * 8, BASE_HEX);
		fractal->palette[i] = ft_atoi_base(hex, BASE_HEX);
		if (hex)
			free(hex);
		i++;
	}
	fractal->palette[i] = 0;
}

int	get_color(int i, t_fractal *fractal)
{
	if (i < 0)
		i = 0;
	if (i > NB_ITER)
		i = NB_ITER - 1;
	return (fractal->palette[i]);
}
