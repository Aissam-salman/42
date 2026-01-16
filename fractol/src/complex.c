/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:56:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/15 20:00:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//  Linear interpolation
double scale_between(double num, double min_target, double max_target, 
                     double min_origin, double max_origin)
{
    return ((max_target - min_target) * (num - min_origin) / (max_origin - min_origin) + min_target);
}

t_complex sum_complex(t_complex z, t_complex c)
{
    t_complex out;

    out.x = z.x + c.x;
    out.y = z.y + c.y;
    return (out);
}

t_complex square_complex(t_complex z)
{
    t_complex tmp;

    tmp.x = (z.x * z.x) - (z.y * z.y);
    tmp.y = 2 * z.x * z.y;
    return (tmp);
}

void choice_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "Julia", 5))
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}

double lerp(double v0, double v1, double t) {
  return (1 - t) * v0 + t * v1;
}

static int palette[256] = {
0x050514,0x060516,0x070618,0x08061A,0x09071C,0x0A071E,0x0B0820,0x0C0822,
0x0E0924,0x100926,0x120A28,0x140A2A,0x160B2C,0x180B2E,0x1A0C30,0x1C0C32,
0x1E0D34,0x200D36,0x220E38,0x240E3A,0x260F3C,0x280F3E,0x2A1040,0x2C1042,
0x2E1144,0x301146,0x321248,0x34124A,0x36134C,0x38134E,0x3A1450,0x3C1452,
0x3E1554,0x401556,0x421658,0x44165A,0x46175C,0x48175E,0x4A1860,0x4C1862,
0x4E1964,0x501966,0x521A68,0x541A6A,0x561B6C,0x581B6E,0x5A1C70,0x5C1C72,
0x5E1D74,0x601D76,0x621E78,0x641E7A,0x661F7C,0x681F7E,0x6A2080,0x6C2082,
0x6E2184,0x702186,0x722288,0x74228A,0x76238C,0x78238E,0x7A2490,0x7C2492,
0x7E2594,0x802596,0x822698,0x84269A,0x86279C,0x88279E,0x8A28A0,0x8C28A2,
0x8E29A4,0x9029A6,0x922AA8,0x942AAA,0x962BAC,0x982BAE,0x9A2CB0,0x9C2CB2,
0x9E2DB4,0xA02DB6,0xA22EB8,0xA42EBA,0xA62FBC,0xA82FBE,0xAA30C0,0xAC30C2,
0xAE31C4,0xB031C6,0xB232C8,0xB432CA,0xB633CC,0xB833CE,0xBA34D0,0xBC34D2,
0xBE35D4,0xC035D6,0xC236D8,0xC436DA,0xC637DC,0xC837DE,0xCA38E0,0xCC38E2,
0xCE39E4,0xD039E6,0xD23AE8,0xD43AEA,0xD63BEC,0xD83BEE,0xDA3CF0,0xDC3CF2,
0xDE3DF4,0xE03DF6,0xE23EF8,0xE43EFA,0xE63FFC,0xE83FFE,0xEA40FF,0xEC42FF,
0xEE44FF,0xF046FF,0xF248FF,0xF44AFF,0xF64CFF,0xF84EFF,0xFA50FF,0xFC52FF,
0xFF54F0,0xFF56E0,0xFF58D0,0xFF5AC0,0xFF5CB0,0xFF5EA0,0xFF6090,0xFF6280,
0xFF6470,0xFF6660,0xFF6850,0xFF6A40,0xFF6C30,0xFF6E20,0xFF7010,0xFF7200,
0xFF8400,0xFF9600,0xFFA800,0xFFBA00,0xFFCC00,0xFFDE00,0xFFF000,0xF8FF20,
0xE0FF40,0xC8FF60,0xB0FF80,0x98FFA0,0x80FFC0,0x68FFE0,0x50FFFF,0x30E8FF,
0x20D0FF,0x10B8FF,0x00A0FF,0x0088FF,0x0070FF,0x0058FF,0x0040FF,0x0028FF,
0x0010FF,0x0000FF,0x0000E0,0x0000C0,0x0000A0,0x000080,0x000060,0x000040
};

double smooth_color(t_complex z, int i)
{
    double iter; 

    double log_zn = log(z.x *z.x + z.y * z.y) / 2;
    double nu = log(log_zn / log(2)) / log(2);
    iter = i + 1 - nu;
    return (iter);
}

void handle_cordinate(int x, int y, t_fractal *fractal)
{
    t_complex z; t_complex c;
    unsigned int i;
    int color;
    double iter;

    z.x = (scale_between(x,-2, +2, 0, WIDTH) * fractal->zoom) + fractal->offset_x;
    z.y = (scale_between(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->offset_y;
    choice_set(&z, &c, fractal);
    i = 0;
    iter = 0;
    while (i < fractal->max_iter)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->blows_up_val)
        {
            iter = smooth_color(z, i);
            color = (int)lerp(palette[(int)floor(iter) & 255], 
                              palette[(int)(floor(iter)+ 1) & 255], i);
            my_mlx_pixel_put(&fractal->image, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->image, x, y, palette[255]);
}
