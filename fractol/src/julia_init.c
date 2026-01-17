/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:42:51 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/17 17:36:47 by alamjada         ###   ########.fr       */
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

double	ft_atod(char *s)
{
	long	unit;
	double	flt;
	double	power;
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
	while (s[i] && s[i] != '.')
		unit = (unit * 10) + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	flt = after_dot(s, i);
	return ((unit + flt) * sign);
}

void	julia(char *x, char *y)
{
	t_fractal	fractal;

	fractal.julia_x = ft_atod(x);
	fractal.julia_y = ft_atod(y);
	init(&fractal, "Julia");
	render(&fractal);
	mlx_loop(fractal.mlx_connection);
}
