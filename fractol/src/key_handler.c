/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:03:01 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 20:03:28 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int handle_hook_key(int keycode, t_fractal *fractal)
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
    render(fractal);
    return (0);
}

int handle_hook_mouse(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    if (button == SCROLL_UP)
        fractal->zoom *= 0.95;
    if (button == SCROLL_DOWN)
        fractal->zoom *= 1.05;
    render(fractal);
    return (0);
}
int close_window (t_fractal *fractal)
{
    all_clear(fractal);
    return (0);
}
