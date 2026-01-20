/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:33:29 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 16:25:45 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_hook_key(int keycode, t_fractal *fractal)
{
	(void)fractal;
	if (keycode == ESC)
		all_clear(fractal);
	else if (keycode == UP)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == DOWN)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == LEFT)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == RIGHT)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == INCRESER)
		fractal->max_iter += 10;
	else if (keycode == DECRESER)
		fractal->max_iter -= 10;
	compute(fractal);
	render(fractal);
	return (0);
}

void switch_color(t_fractal *fractol) 
{
	if (fractol->palette_num == 1)
	{
		fractol->palette_num += 1;
		palette2(fractol);
	}
	else if (fractol->palette_num == 2)
	{
		fractol->palette_num += 1;
		palette3(fractol);
	}
	else if (fractol->palette_num == 3)
	{
		fractol->palette_num += 1;
		palette4(fractol);
	}
	else
	{
		fractol->palette_num = 1;
		palette1(fractol);
	}
	free(fractol->palette);
	generate_palette(fractol);
}
# define CLICK_LEFT 1

int	handle_hook_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == CLICK_LEFT)
		switch_color(fractal);
	if (button == SCROLL_UP)
		fractal->zoom *= 0.95;
	if (button == SCROLL_DOWN)
		fractal->zoom *= 1.05;
	compute(fractal);
	render(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	all_clear(fractal);
	return (0);
}
