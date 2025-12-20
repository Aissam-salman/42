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

#define WIN_W 1980
#define WIN_H 1080
#define MARGIN 50

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
	close(mlx->fd);
	free(mlx);
	exit(EXIT_SUCCESS);
}

int handle_input_callback(int keycode, t_mlx *mlx)
{
	if (keycode == 65307) 
		close_window(mlx);
	else 
		printf("KEY: %d\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{	
	char	*dst;

	if (x < 0 || y < 0 || x >= 1980 || y >= 1080)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/* Algorithm DDA 
    *si |x2-x1| >= |y2-y1| alors
            longueur := |x2-x1|
    sinon
        longueur := |y2-y1|
    fin si
    dx := (x2-x1) / longueur
    dy := (y2-y1) / longueur
    x := x1 + 0.5
    y := y1 + 0.5
    i := 1
    tant que i ≤ longueur faire
    setPixel (E (x), E (y))
    x := x + dx
    y := y + dy
    i := i + 1
    fin tant que
*/
void draw_line(int x1, int y1, int x2, int y2, int color, t_data *img)
{
    double dx;
    double dy;
    double x;
    double y;
    int len;
    int i;
   
    if (x2 - x1 >= y2 - y1)
        len = x2 - x1;
    else 
        len = y2 - y1;
	dx = abs((x2 - x1) / len);
	dy = abs((y2 - y1) / len);
	x = x1 + 0.5;
	y = y1 + 0.5;
    i = 0;
    while (i < len)
    {
		my_mlx_pixel_put(img, (int)x, (int)y, color);
		x += dx;
		y += dy;
        i++;
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
    double angle;

	angle= 30.0 * M_PI / 180.0;
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

int   extract_parsing_file(char *filename, t_mlx **mlx)
{
    t_mlx *p_mlx;

    if (!filename)
    {
        perror("Error with filename\n");
        exit(EXIT_FAILURE);
    }
    p_mlx = *mlx;
    p_mlx->fd = -1;


}

int main(int ac, char **av) {
	t_mlx   *mlx;
    int is_extracted;

    if (ac != 2)
    {
        perror("Error args empty, need one\n");
    }
    mlx = malloc(sizeof(t_mlx));
    if (!mlx)
    {
		printf("Error with alloc mlx: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    extract_parsing_file(av[1], &mlx);
}
