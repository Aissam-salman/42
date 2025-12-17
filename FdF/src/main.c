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
#include <limits.h>

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
	// free(mlx->head);
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
	if (x < 0 || y < 0 || x >= 1980 || y >= 1080)
		return;
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(int x1, int y1, int x2, int y2, int color, t_data *img)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	int step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

	dx /= step;
	dy /= step;
	double x = x1;
	double y = y1;

	for (int i = 0; i <= step; i++)
	{
		my_mlx_pixel_put(img, (int)x, (int)y, color);
		x += dx;
		y += dy;
	}
}

t_point *get_point(t_point *head, int index)
{
	int i = 0;
	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	return head;
}

void draw_map(t_point *head, t_data *img)
{
	while (head)
	{
		my_mlx_pixel_put(img, head->xp, head->yp, head->color);
		if (head->right)
			draw_line(head->xp, head->yp,
				head->right->xp, head->right->yp,
				head->color, img);
		if (head->down)
			draw_line(head->xp, head->yp,
				head->down->xp, head->down->yp,
				head->color, img);
		head = head->next;
	}
}

#define WIN_W 1980
#define WIN_H 1080
#define MARGIN 50

void compute_scale_and_offset(t_point *head, double *scale, int *ox, int *oy)
{
    int min_x = INT_MAX, max_x = INT_MIN;
    int min_y = INT_MAX, max_y = INT_MIN;
    double angle = 30.0 * M_PI / 180.0;

    // première passe : projet temporaire avec scale = 1
    t_point *tmp = head;
    while (tmp)
    {
        int xp = (tmp->x - tmp->y) * cos(angle);
        int yp = ((tmp->x + tmp->y) * sin(angle) - tmp->z);
        if (xp < min_x) min_x = xp;
        if (xp > max_x) max_x = xp;
        if (yp < min_y) min_y = yp;
        if (yp > max_y) max_y = yp;
        tmp = tmp->next;
    }

    // calcul du scale pour que la map rentre dans la fenêtre
    double scale_x = (double)(WIN_W - 2 * MARGIN) / (max_x - min_x);
    double scale_y = (double)(WIN_H - 2 * MARGIN) / (max_y - min_y);
    *scale = fmin(scale_x, scale_y);

    // calcul de l'offset pour centrer
    *ox = WIN_W / 2 - (min_x + max_x) / 2 * (*scale);
    *oy = WIN_H / 2 - (min_y + max_y) / 2 * (*scale);
}

void project_iso(t_point *p, double scale, int ox, int oy)
{
    double angle = 30.0 * M_PI / 180.0;
    p->xp = (p->x - p->y) * cos(angle) * scale + ox;
    p->yp = ((p->x + p->y) * sin(angle) - p->z) * scale + oy;
}

void project_all_points(t_point *head)
{
    double scale;
    int ox, oy;

    compute_scale_and_offset(head, &scale, &ox, &oy);
    t_point *tmp = head;
    while (tmp)
    {
        project_iso(tmp, scale, ox, oy);
        tmp = tmp->next;
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
	int width;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->head = NULL;
	mlx->fd = -1;
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
		if (y == 0)
		{
			width = 0;
			while (splited[width])
				width++;
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
			if (x > 0)
			{
				t_point *prev = get_point(head, y * width + x - 1);
				prev->right = node;
			}
			if (y > 0)
			{
				t_point *up = get_point(head, (y - 1) * width + x);
				up->down = node;
			}
			ft_node_add_back(&head, node);
			x++;
		}
		free_array(splited);
		y++;
	}
	project_all_points(head);
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
	draw_map(head, &mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	mlx_key_hook(mlx->win, handle_input_callback, mlx);
	mlx_hook(mlx->win, 33, 1L<<17, close_window, mlx);
	mlx_loop(mlx->ptr);
	return (EXIT_SUCCESS);
}
