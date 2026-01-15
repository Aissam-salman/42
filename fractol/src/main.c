/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:34:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 13:55:31 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void complex_test()
{
    t_complex z;
    // point 
    t_complex c;
    double tmp_real;

    z.r = 0;
    z.i = 0;

    c.r = 0.24;
    c.i = 0.4;

    for(int i = 0; i < 42; ++i)
    {
        // z = z*z + c
        tmp_real = (z.r * z.r) - (z.i * z.i);
        z.i = 2 * z.r * z.i;
        z.r = tmp_real;

        // add c 
        z.r += c.r;
        z.i += c.i;
        ft_printf("i= %d, r= %f, i= %f\n",i, z.r, z.i);
    }
}

int main(int ac, char **av)
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

// 2 params
// ./fractol mandelbrot
// ./fractol julia "r" "i"
