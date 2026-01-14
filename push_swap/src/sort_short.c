/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:48:04 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:43:28 by alamjada         ###   ########.fr       */
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

void	sort_short(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (!check_is_stack_sorted(stack))
	{
		if (head->value > ft_node_last(head)->value)
			rotate(stack, "ra");
		else if (head->value > head->next->value)
			swap(stack, "sa");
		head = *stack;
	}
	update_index(stack);
}
