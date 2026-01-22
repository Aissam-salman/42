/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:44:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/22 15:34:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	palette1(t_fractal *fractal)
{
	fractal->color1 = COLOR1;
	fractal->color2 = COLOR2;
	fractal->color3 = COLOR3;
	fractal->color4 = COLOR4;
}

void	palette2(t_fractal *fractal)
{
	fractal->color1 = 0x000000;
	fractal->color2 = 0xBC00DD;
	fractal->color3 = 0x00DDEB;
	fractal->color4 = 0xFFFFFF;
}

void	palette3(t_fractal *fractal)
{
	fractal->color1 = 0x000000;
	fractal->color2 = 0x9A0000;
	fractal->color3 = 0xFF8C00;
	fractal->color4 = 0xFFED00;
}

void	palette4(t_fractal *fractal)
{
	fractal->color1 = 0x000505;
	fractal->color2 = 0x003300;
	fractal->color3 = 0x7FFF00;
	fractal->color4 = 0xFBFFB0;
}
