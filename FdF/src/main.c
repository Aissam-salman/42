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

// create data struct for storing coordinates (x,y,z, color, xp, yp)
// render mini : isometric projection 

int main(int ac, char **av)
{
	int fd;
	size_t x;
	size_t	y;
	int z;
	int color;
	char	*line;
	t_point *head;
	t_point	*point;
	t_point	*tmp;

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
		ft_printf("Line %d: %s", y, line);
		char **splited = ft_split(line, ' ');
		if (!splited || !*splited)
		{
			perror("Error parsing file");
			exit(EXIT_FAILURE);
		}
		x = 0;
		while (splited[x])
		{
			// 4,0xff
			ft_printf("splited[%d]: %s\n", x, splited[x]);
			char **data = ft_split(splited[x], ',');
			z = ft_atoi(data[0]);
			color = 0xFFFFFF;
			if (data[1])
			{
			 color = ft_atoi_base(data[1], "0123456789abcdef");
			}
			point = ft_node_new(x, y, z, color);
			ft_printf("x= %d, y= %d, z= %d, color= %x\n", point->x, point->y, point->z, 		point->color);
			x++;
		}
		pause();
		tmp = point;
		ft_node_add_back(&head, point);
		ft_node_delone(tmp);
		free(line);
		y++;
    }

		// 0 0 0 0
		// 0 2 3 0
		// 0 0 0 0  
	while (head->next)
	{
		ft_printf("x= %f, y= %f, z= %f\n", head->x, head->y, head->z);
		head = head->next;
	}
	// parcours tab > |  extract x, y, z

	close(fd);
    return (EXIT_SUCCESS);
}
