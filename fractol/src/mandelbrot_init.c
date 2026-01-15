/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:41:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 20:04:40 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// z = z*z + c
void mandelbrot()
{
    t_fractal fractal;

    init(&fractal, "Mandelbrot");
    render(&fractal);
    mlx_loop(fractal.mlx_connection);
}
