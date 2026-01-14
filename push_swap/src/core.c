/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:03:39 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:42:39 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>
#include <unistd.h>

static void	find_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*sa;
	t_node	*sb;
	t_node	*min;

	if (!*stack_b)
		return ;
	sb = *stack_b;
	while (sb)
	{
		sa = *stack_a;
		min = NULL;
		while (sa)
		{
			if (sb->value < sa->value)
			{
				if (!min || min->value > sa->value)
					min = sa;
			}
			sa = sa->next;
		}
		if (!min)
			min = find_min(*stack_a);
		sb->target = min;
		sb = sb->next;
	}
}

static void	pricing(t_node **stack_a, t_node **stack_b)
{
	t_node	*hb;
	int		sizeb;
	int		sizea;
	int		cost;

	if (!*stack_b)
		return ;
	hb = *stack_b;
	sizeb = ft_node_size(*stack_b);
	sizea = ft_node_size(*stack_a);
	while (hb)
	{
		cost = 0;
		if (hb->index <= sizeb / 2)
			cost = hb->index;
		else
			cost = sizeb - hb->index;
		if (hb->target->index <= sizea / 2)
			cost += hb->target->index;
		else
			cost += sizea - hb->target->index;
		hb->cost = cost;
		hb = hb->next;
	}
}

static void	move_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	if (!*stack_b)
		return ;
	cheapest = find_min_cost_node(*stack_b);
	while (*stack_b && cheapest->index != 0)
	{
		if (cheapest->index < ft_node_size(*stack_b) / 2)
			rotate(stack_b, "rb");
		else
			reverse_rotate(stack_b, "rrb");
		update_index(stack_b);
		cheapest = find_min_cost_node(*stack_b);
	}
	while (*stack_a && (*stack_a)->value != cheapest->target->value)
	{
		if (cheapest->target->index > ft_node_size(*stack_a) / 2)
			reverse_rotate(stack_a, "rra");
		else
			rotate(stack_a, "ra");
		update_index(stack_a);
	}
	push_a(stack_b, stack_a);
	update_stacks_index(stack_a, stack_b);
}

static void	sort_turk(t_node **stack_a, t_node **stack_b)
{
	while (ft_node_size(*stack_a) >= 3)
		push_b(stack_a, stack_b);
	sort_short(stack_a);
	update_stacks_index(stack_a, stack_b);
	while (*stack_b)
	{
		find_target(stack_a, stack_b);
		pricing(stack_a, stack_b);
		move_cheapest(stack_a, stack_b);
	}
	while (find_min(*stack_a)->value != (*stack_a)->value)
		rotate(stack_a, "ra");
}

void	push_swap(t_node **stack, int size)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (size <= 3)
		sort_short(stack);
	else
		sort_turk(stack, &stack_b);
	if (stack_b)
		free_stack(&stack_b);
}
