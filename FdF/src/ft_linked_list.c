/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:21:10 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 18:20:35 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_point	*ft_node_new(int x, int y, int z, int color)
{
	t_point	*new_node;

	new_node = malloc(sizeof(t_point));
	if (!new_node)
	{
		ft_printf("Error allocation memory %s\n", strerror(errno));
		return (NULL);
	}
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->color = color;
	new_node->xp = 0;
	new_node->yp = 0;
	new_node->down = NULL;
	new_node->right = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_point	*ft_node_last(t_point *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_node_add_back(t_point **lst, t_point *new_node)
{
	t_point	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = ft_node_last(*lst);
		last->next = new_node;
	}
}

void	ft_node_delone(t_point *lst)
{
	if (!lst)
		return ;
	lst->next = NULL;
	free(lst);
}

void	ft_node_clear(t_point **lst)
{
	t_point	*head;
	t_point	*tmp;

	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		ft_node_delone(head);
		head = tmp;
	}
	*lst = NULL;
}
