/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/22 15:34:49 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	start(char *name, char *c1, char *c2)
{
	t_fractal	fractal;
	double		params1;
	double		params2;

	if (ft_strncmp(name, "julia", 5) == 0)
	{
		if (ft_atod_safe(c1, &params1) == -1)
			error_params();
		if (ft_atod_safe(c2, &params2) == -1)
			error_params();
		fractal.julia_x = params1;
		fractal.julia_y = params2;
	}
	init(&fractal, name);
	compute(&fractal);
	render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		error_params();
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		start("mandelbrot", NULL, NULL);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		start("julia", av[2], av[3]);
	else
		error_params();
	return (0);
}
