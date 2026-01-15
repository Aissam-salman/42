/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:56:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 20:00:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//  Linear interpolation
double scale_between(double num, double min_target, double max_target, 
                     double min_origin, double max_origin)
{
    return ((max_target - min_target) * (num - min_origin) / (max_origin - min_origin) + min_target);
}

t_complex sum_complex(t_complex z, t_complex c)
{
    t_complex out;

    out.x = z.x + c.x;
    out.y = z.y + c.y;
    return (out);
}

t_complex square_complex(t_complex z)
{
    t_complex tmp;

    tmp.x = (z.x * z.x) - (z.y * z.y);
    tmp.y = 2 * z.x * z.y;
    return (tmp);
}

void choice_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "Julia", 5))
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

void handle_cordinate(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    unsigned int i;
    int color;

    z.x = (scale_between(x,-2, +2, 0, WIDTH) * fractal->zoom) + fractal->offset_x;
    z.y = (scale_between(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->offset_y;
    choice_set(&z, &c, fractal);
    i = 0;
    while (i < fractal->max_iter)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->blows_up_val)
        {
            color = scale_between(i, BLACK, WHITE, 0, fractal->max_iter);
            my_mlx_pixel_put(&fractal->image, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->image, x, y, BLACK);
}
