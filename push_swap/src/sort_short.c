/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:48:04 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/21 10:52:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_stack_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head)
	{
		if (head->next && head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_max_index(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max->index);
}

void	sort_short(t_node **stack)
{
	int	max_index;

	max_index = find_max_index(*stack);
	if (max_index == 0)
		rotate(stack, "ra");
	else if (max_index == 1)
		reverse_rotate(stack, "rra");
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, "sa");
	update_index(stack);
}
