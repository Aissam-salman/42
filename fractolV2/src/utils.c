/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:42:10 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 14:02:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_isspace(unsigned char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static double	after_dot(char *s, int i)
{
	double	power;
	double	flt;

	power = 1;
	flt = 0.0;
	while (s[i])
	{
		power /= 10;
		flt = flt + (s[i++] - '0') * power;
	}
	return (flt);
}

int	ft_atod_safe(char *s, double *res)
{
	long	unit;
	double	flt;
	int		sign;
	int		i;

	unit = 0;
	flt = 0.0;
	sign = 1;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (!ft_isdigit(s[i]))
		return (-1);
	while (ft_isdigit(s[i]) && s[i] != '.')
		unit = (unit * 10) + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	flt = after_dot(s, i);
	*res = (unit + flt) * sign;
	return (1);
}

double	lerp(double v0, double v1, double t)
{
	return ((1 - t) * v0 + t * v1);
}

void	all_clear(t_fractal *fractal)
{
	free(fractal->palette);
	mlx_destroy_image(fractal->mlx_connection, fractal->img.p_img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}
