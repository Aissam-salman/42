/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:26:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 15:56:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->limits = 4;
	fractal->max_iter = NB_ITER;
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->palette_num = 1;
	fractal->color1 = COLOR1;
	fractal->color2 = COLOR2;
	fractal->color3 = COLOR3;
	fractal->color4 = COLOR4;
}

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
	fractal->img.p_img = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractal->img.p_img)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.p_img,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	hook_and_data_init(fractal);
}
