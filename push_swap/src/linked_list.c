/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:50:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 20:01:17 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_node_new(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->value = value;
	new_node->index = index;
    new_node->target = NULL;
	return (new_node);
}

t_node	*ft_node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_node_add_back(t_node **lst, t_node *new_node)
{
	t_node	*last;

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


void	ft_node_delone(t_node *node)
{
	if (!node)
		return ;
	node->next = NULL;
	free(node);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("stack[%d] = %d\n", 
            stack->index, 
            stack->value);
            stack = stack->next;
	}
}

void print_stack_t(t_node *stack)
{
	while (stack)
	{
		ft_printf("stack[%d] = %d\n target= [%d]: %d\n cost= %d\n", 
            stack->index, 
            stack->value, 
            stack->target ? stack->target->index : -1, 
            stack->target ? stack->target->value : -1,
            stack->cost);
            stack = stack->next;
	}
}

int	ft_node_size(t_node *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
