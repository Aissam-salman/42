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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_mlx {
	void	*ptr;
	void	*window;
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

void draw_line()
{

	// y = mx + b
}


void draw_map()
{}

int print_fdf(t_mlx *mlx)
{
	t_point *tmp;
	tmp = mlx->head;
	while (tmp != NULL)
	{
		mlx_pixel_put(mlx->ptr, mlx->window, tmp->xp / 2, tmp->yp /2, tmp->color);
		tmp = tmp->next;
	}
	return (0);
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->window);
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
	else if (keycode == 100) //D
		print_fdf(mlx);
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
	if (!mlx.ptr)
	{
		printf("Error with minilibx init: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	mlx.window = mlx_new_window(mlx.ptr, 1980, 1080, "FDF");
	if (!mlx.window)
	{
		printf("Error with minilibx new window: %s\n", strerror(errno));
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		exit(EXIT_FAILURE);
	}
	mlx.fd = fd;
	mlx.head = head;
	//handle keycode
	mlx_key_hook(mlx.window, handle_input_callback, &mlx);
	mlx_hook(mlx.window, 33, 1L<<17, close_window, &mlx);

	//handle exit btn
	// mlx_pixel_put(mlx.ptr, mlx.window, 1980/2, 1080/2, 0xFFFFFF);
	t_point *tmp;
	tmp = head;
	while (tmp != NULL)
	{
		int offset_x = 400;
		int offset_y = 300;
		printf("x=%d y=%d\n", tmp->xp, tmp->yp);
		mlx_pixel_put(mlx.ptr, mlx.window, tmp->xp + offset_x, tmp->yp + offset_y, 0xFFFFFF);
		tmp = tmp->next;
	}
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
