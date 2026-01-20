/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:33:48 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 12:34:47 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win,
		fractal->img.p_img, 0, 0);
}
