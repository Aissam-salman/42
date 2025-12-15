/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:36:17 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 18:22:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	t_data  img;
	int	fd;
	t_point *head;
} t_mlx;

void free_array(char **data)  
{
	size_t i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx;
	int dy;
	int x;
	int y;
	int err;
	int tmp;
	int right;
	int down;

	dx = abs(x1 - x0);
	right = dx > 0;
	if (!right)
		dx = -dx;
	dy = abs(y1 - y0);
	down = dy > 0;
	if (down)
		dy = -dy;
	err = dx + dy;
	x = x0;
	y = y0;

	while(1)
	{
		my_mlx_pixel_put(data, x, y, 0xFFFFFF);
		if  (x == x1 && y == y1)
			break;
		tmp = err << 1;
		if (tmp > dy)
		{
			err += dy;
			if (right)
				x++;
			else
				x--;
		}
		if (tmp < dx)
		{
			err += dx;
			if (down)
				y++;
			else
				y--;
		}
	}


}


void draw_map()
{}


int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_node_clear(&mlx->head);
	close(mlx->fd);
	exit(EXIT_SUCCESS);
}

int handle_input_callback(int keycode, t_mlx *mlx)
{
	if (keycode == 65307) //ESC
		close_window(mlx);
	else 
		printf("KEY: %d\n", keycode);
	return (0);
}

int main(int ac, char **av) {
	int fd;
	int x;
	int y;
	int z;
	int color;
	char *line;
	t_point *head;
	t_point *node;
	char **data;
	char **splited;
	t_mlx mlx;
	t_point *tmp;

	if (ac != 2) 
	{
		ft_printf("Error number args!\nUsage: %s \"filename\"\n", av[0]);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1) 
	{
		printf("Error opening file: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	head = NULL;
	y = 0;
	while ((line = get_next_line(fd)) != NULL) 
	{
		splited = ft_split(line, ' ');
		if (!splited || !*splited) 
		{
			perror("Error parsing file");
			exit(EXIT_FAILURE);
		}
		free(line);
		x = 0;
		while (splited[x]) 
		{
			data = ft_split(splited[x], ',');
			z = ft_atoi(data[0]);
			color = 0xFFFFFF;
			if (data[1])
				color = ft_atoi_base(data[1], "0123456789abcdef");
			free_array(data);
			node = ft_node_new(x, y, z, color);
			ft_node_add_back(&head, node);
			x++;
		}
		free_array(splited);
		y++;
	}

	t_point *lst;
	lst = head;
	while (lst != NULL)
	{
		lst->xp = (int)(lst->x - lst->y) * cos(30.0);
		lst->yp = (int)(lst->x + lst->y) * sin(30.0) - lst->z;
		lst = lst->next;
	}
	/*
	 * isometric projection
		x’ = (x - y) × cos(30°)
		y’ = (x + y) × sin(30°) - z**

		x − y → rotation de 45°
		x + y → rotation de 45° (autre composante)
		− z → gestion de la hauteur (élévation vers le haut de l’écran)
	*/
	// MINILIX

	mlx.ptr = mlx_init();
	// if (!mlx.ptr)
	// {
	// 	printf("Error with minilibx init: %s\n", strerror(errno));
	// 	exit(EXIT_FAILURE);
	// }
	mlx.win = mlx_new_window(mlx.ptr, 1980, 1080, "FDF");
	// if (!mlx.win)
	// {
	// 	printf("Error with minilibx new img: %s\n", strerror(errno));
	// 	mlx_destroy_display(mlx.ptr);
	// 	free(mlx.ptr);
	// 	exit(EXIT_FAILURE);
	// }
	mlx.img.img = mlx_new_image(mlx.ptr, 1980, 1080);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.fd = fd;
	mlx.head = head;

	tmp = head;
	while (tmp != NULL)
	{
		my_mlx_pixel_put(&mlx.img, tmp->xp + 30, tmp->yp + 40, tmp->color);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.win, handle_input_callback, &mlx);
	mlx_hook(mlx.win, 33, 1L<<17, close_window, &mlx);
	mlx_loop(mlx.ptr);

	// ft_node_clear(head);
	// free(head);
	// close(fd);
	return (EXIT_SUCCESS);
}
// 4,0xff
// 0 0 0 0
// 0 2 3 0
// 0 0 0 0
