/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:33:48 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/22 15:31:42 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
		*(unsigned int *)(data->addr + offset) = color;
	}
}

void	render(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win,
		fractal->img.p_img, 0, 0);
}
