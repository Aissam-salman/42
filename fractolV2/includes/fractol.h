/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:23 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/22 15:38:47 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// SIZE
# define WIDTH 1000
# define HEIGHT 1000

# define NB_ITER 60
# define COLOR1 0x251d3a
# define COLOR2 0xff7700
# define COLOR3 0xe04d01
# define COLOR4 0x2a2550
// KEYCODE
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define INCRESER 105 // i
# define DECRESER 107 // k
// MOUSE
# define CLICK_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5
// COLOR
# define BLACK 0x000000

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_color_rgb
{
	int				r;
	int				g;
	int				b;
}					t_color_rgb;

typedef struct s_complex
{
	double			x;
	double			y;

}					t_complex;

typedef struct s_img
{
	void			*p_img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_fractal
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_win;
	t_img			img;
	double			limits;
	double			zoom;
	double			offset_x;
	double			offset_y;
	double			julia_x;
	double			julia_y;
	int				*palette;
	unsigned short	max_iter;
	int				palette_num;
	int				color1;
	int				color2;
	int				color3;
	int				color4;
}					t_fractal;

// core
void				compute(t_fractal *fractal);
void				render(t_fractal *fractal);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);

// UTILS
int					ft_atod_safe(char *s, double *res);
void				all_clear(t_fractal *fractal);
double				lerp(double v0, double v1, double t);
//  Linear interpolation
double				scale_between(double num, double min_target,
						double max_target, double max_origin);
// ERROR
void				error_params(void);
void				error_malloc(void);

void				init(t_fractal *fractal, char *name);
// KEY
int					handle_hook_key(int keycode, t_fractal *fractal);
int					handle_hook_mouse(int button, int x, int y,
						t_fractal *fractal);
int					close_window(t_fractal *fractal);

// COLOR
void				generate_palette(t_fractal *fractal);
int					get_color(int i, t_fractal *fractal);
double				smooth_color(t_complex z, int i);

void				palette1(t_fractal *fractal);
void				palette2(t_fractal *fractal);
void				palette3(t_fractal *fractal);
void				palette4(t_fractal *fractal);
#endif
