/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:22:29 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 16:31:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../lib/libft/includes/ft_printf.h"
#include "../lib/libft/includes/libft.h"
#include "../lib/libft/includes/get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	float	color;
	float	xp;
	float	yp;
	struct s_point *next; 
} t_point;

#endif
