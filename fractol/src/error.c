/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:24:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 13:26:33 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/includes/libft.h"

void    display_rules_params_exit(void)
{
    ft_putendl_fd("Error params not correct!\n", 2);
    ft_printf("---- PARAMS ----\n./fractol mandelbrot\nor\n");
    ft_printf("./fratol julia [real] [imaginary]\n\nexample:\n");
    ft_printf("./factol julia −0.8 0.156\n");
    exit(EXIT_FAILURE);
}
