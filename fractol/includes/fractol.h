/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:31:24 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 13:52:42 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1920
#define HEIGHT 1080

// KEYCODE
#define ESC 65307

#include "../lib/libft/includes/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

typedef struct s_complex
{
    // real
    double x;
    // imaginary
    double y;
} t_complex;

typedef struct s_img 
{
    void *p_img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_win;
    t_img image;
} t_fractal;

// ERROR
void    display_rules_params_exit(void);

// CORE
void mandelbrot();
void julia(char *x, char *y);

#endif 
