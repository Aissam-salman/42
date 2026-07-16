/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:27:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 12:27:54 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_params(void)
{
	ft_putendl_fd("Error params not correct!\n", 2);
	ft_printf("---- PARAMS ----\n./fractol mandelbrot\nor\n");
	ft_printf("./fratol julia [real] [imaginary]\n\nexample:\n");
	ft_printf("./factol julia −0.8 0.156\n");
	exit(EXIT_FAILURE);
}

void	error_malloc(void)
{
	perror("Error with malloc!");
	exit(EXIT_FAILURE);
}
