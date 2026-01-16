/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:34:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/16 19:35:49 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		display_rules_params_exit();
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		mandelbrot();
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		julia(av[2], av[3]);
	else
		display_rules_params_exit();
	return (0);
}
