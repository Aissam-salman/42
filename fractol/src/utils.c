/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:01:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/16 19:37:42 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	all_clear(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.p_img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal->palette);
	exit(EXIT_SUCCESS);
}
