/* ************r************************************************************* */
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

typedef struct s_mlx{
	void	*ptr;
	void	*win;
	t_data  img;
	int	fd;
	struct s_point *head;
} t_mlx;

void free_array(char **data)  
{
	size_t i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_node_clear(&mlx->head);
	free(mlx->head);
	close(mlx->fd);
	free(mlx);
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(int x1, int y1, int x2, int y2, int color, t_data *img)
{
	int dx;
	int dy;
	int step;
	int xin;
	int yin;
	int i;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx >= dy)
		step = dx;
	else 
		step = dy;
	xin = dx / step;
	yin = dy / step;
	x = x1 + 0.5;
	y = y1 + 0.4;
	i = 0;
	while (i < step)
	{ x = x + xin;
		y = y + yin;
		my_mlx_pixel_put(img, x, y, color);
		i++;
	}
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
	t_mlx *mlx;
	// t_point *tmp;

	mlx = malloc(sizeof(t_mlx));
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
		lst->xp = lst->x * cos(120.0) + lst->y * cos(120.0 + 2) + lst->z * cos(120.0 - 2);
		lst->yp = lst->x * sin(120.0) + lst->y * sin(120.0 + 2) + lst->z * sin(120.0 - 2);
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

	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		printf("Error with minilibx init: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	mlx->win = mlx_new_window(mlx->ptr, 1980, 1080, "FDF");
	if (!mlx->win)
	{
		printf("Error with minilibx new img: %s\n", strerror(errno));
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
	mlx->img.img = mlx_new_image(mlx->ptr, 1980, 1080);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mlx->fd = fd;
	mlx->head = head;

	while (head)
	{

		t_point *p = head;
		if (head->next)
			head = head->next;
		if (head)
			draw_line(p->xp, p->yp, head->xp, head->yp,head->color, &mlx->img);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	mlx_key_hook(mlx->win, handle_input_callback, mlx);
	mlx_hook(mlx->win, 33, 1L<<17, close_window, mlx);
	mlx_loop(mlx->ptr);
	return (EXIT_SUCCESS);
}
