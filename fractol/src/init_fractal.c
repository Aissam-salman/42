/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:04:31 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/17 17:37:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	hook_and_data_init(t_fractal *fractal)
{
	data_init(fractal);
	generate_palette(fractal);
	mlx_key_hook(fractal->mlx_win, handle_hook_key, fractal);
	mlx_mouse_hook(fractal->mlx_win, handle_hook_mouse, fractal);
	mlx_hook(fractal->mlx_win, 33, 1L << 17, close_window, fractal);
}

void	init(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		error_malloc();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.p_img = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractal->image.p_img)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.addr = mlx_get_data_addr(fractal->image.p_img,
			&fractal->image.bits_per_pixel, &fractal->image.line_length,
			&fractal->image.endian);
	hook_and_data_init(fractal);
}
