/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/16 20:11:53 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void generate_palette(t_fractal *fractal)
{
	int i;
	char *hex;

	i = 0;
	fractal->palette = malloc(sizeof(int) * NB_ITER);
	if (!fractal->palette)
		error_malloc();
	while (i < (int)fractal->max_iter)
	{
		hex = ft_itoa_base(i * 8, BASE_HEX);
		fractal->palette[i] = ft_atoi_base(hex,BASE_HEX);
		if (hex)
			free(hex);
		i++;
	}
}

int get_color(int i, t_fractal *fractal)
{
	return (fractal->palette[i]);
}
