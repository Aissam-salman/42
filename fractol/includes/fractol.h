/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:31:24 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 20:09:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 900
#define HEIGHT 900

// KEYCODE
#define ESC 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define INCRESER 105 //i
#define DECRESER 107 //k
// MOUSE
#define SCROLL_UP 4
#define SCROLL_DOWN 5
// COLOR
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define PURPLE 0x660066

#include "../lib/libft/includes/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <limits.h>

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
    double blows_up_val;
    unsigned int max_iter;
    double zoom;
    double offset_x;
    double offset_y;
    double julia_x;
    double julia_y;
} t_fractal;

// INIT
void    init(t_fractal *fractal, char *name);
// DATA
void data_init(t_fractal *fractal);
// DRAW
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
// KEY & MOUSE HANDLER
int handle_hook_key(int keycode, t_fractal *fractal);
int handle_hook_mouse(int button, int x, int y, t_fractal *fractal);
int close_window(t_fractal *fractal);
// RENDERING
void render(t_fractal *fractal);
// UTILS
void all_clear(t_fractal *fractal);
// ERROR
void    display_rules_params_exit(void);
void    error_malloc();
// CORE
void mandelbrot();
void julia(char *x, char *y);
// COMPLEX NUMBER
double scale_between(double num, double min_target, double max_target,
                     double min_origin, double max_origin);
t_complex sum_complex(t_complex z, t_complex c);
t_complex square_complex(t_complex z);
void handle_cordinate(int x, int y, t_fractal *fractal);

#endif
