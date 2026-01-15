/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:41:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 13:41:51 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void error_malloc()
{
    perror("Error with malloc!");
    exit(EXIT_FAILURE);
}

void all_clear(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

#define ESC 65307

int handle_hook_key(int keycode, t_fractal *fractal)
{
    (void)fractal;
    if (keycode == ESC)
        all_clear(fractal);
    ft_printf("Helloo keyyyy, %d\n", keycode);
    return (0);
}

void init(t_fractal *fractal, char *name)
{
    fractal->name = name;
    fractal->mlx_connection = mlx_init();
    if(!fractal->mlx_connection)
        error_malloc();
    fractal->mlx_win = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (!fractal->mlx_win)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();
    }
    fractal->image.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (!fractal->image.img)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();    
    }
    fractal->image.addr = mlx_get_data_addr(fractal->image.img, 
                                             &fractal->image.bits_per_pixel, 
                                             &fractal->image.line_length, 
                                             &fractal->image.endian);
    my_mlx_pixel_put(&fractal->image, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win, fractal->image.img, 0, 0);
    mlx_key_hook(fractal->mlx_win, handle_hook_key, fractal);
    mlx_loop(fractal->mlx_connection);
}


void mandelbrot()
{
    t_fractal fractal;

    init(&fractal, "Mandelbrot");
}
