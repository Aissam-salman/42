/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:41:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/16 19:35:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(void)
{
	t_fractal	fractal;

	init(&fractal, "Mandelbrot");
	render(&fractal);
	mlx_loop(fractal.mlx_connection);
}
