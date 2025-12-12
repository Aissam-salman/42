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

void free_array(char **data)
{
	size_t i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

int main(int ac, char **av) {
	int fd;
	int x;
	int y;
	int z;
	int color;
	char *line;
	t_point **head;
	t_point *node;
	char **data;
	char **splited;

	head = malloc(sizeof(t_point));
	if (!head)
	{
		printf("Error allocation memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
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
			ft_node_add_back(head, node);
			x++;
		}
		free_array(splited);
		y++;
	}

	t_point *lst;
	lst = *head;
	while (lst != NULL)
	{
		ft_printf("x= %d, y= %d, z= %d, color= %d\n", lst->x, lst->y, 
			lst->z, lst->color);
		lst = lst->next;
	}
	ft_node_clear(head);
	free(head);
	// create data struct for storing coordinates (x,y,z, color, xp, yp)
	// render mini : isometric projection
	close(fd);
	return (EXIT_SUCCESS);
}
// 4,0xff
// 0 0 0 0
// 0 2 3 0
// 0 0 0 0
