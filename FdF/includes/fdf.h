/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:22:29 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 18:20:51 by alamjada         ###   ########.fr       */
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
	int	x;
	int	y;
	int z;
	float	color;
	float	xp;
	float	yp;
	struct s_point *next; 
} t_point;


t_point	*ft_node_new(int x, int y, int z, int color);
t_point	*ft_node_last(t_point *lst);
void	ft_node_add_back(t_point **lst, t_point *new_node);
void	ft_node_delone(t_point *lst);
void	ft_node_clear(t_point **lst);

#endif
