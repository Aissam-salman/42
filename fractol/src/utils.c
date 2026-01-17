/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:01:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/17 17:31:39 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	lerp(double v0, double v1, double t)
{
	return ((1 - t) * v0 + t * v1);
}

void	all_clear(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.p_img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal->palette);
	exit(EXIT_SUCCESS);
}
