/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:48:51 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:42:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_cost_index(t_node *stack)
{
	int	min;
	int	index;

	min = stack->cost;
	index = stack->index;
	while (stack)
	{
		if (stack->cost < min)
		{
			min = stack->cost;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

t_node	*find_min_cost_node(t_node *stack)
{
	int	i;

	i = find_min_cost_index(stack);
	while (stack)
	{
		if (stack->index == i)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_node_by_index(t_node *stack, int index)
{
	int	i;

	i = index;
	while (stack)
	{
		if (stack->index == i)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
