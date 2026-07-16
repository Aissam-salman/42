/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:40:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:43:00 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_bis(t_node **stack)
{
	t_node	*head;
	t_node	*nxt;
	t_node	*last;

	head = *stack;
	nxt = head->next;
	last = ft_node_last(head);
	last->next = head;
	head->next = NULL;
	*stack = nxt;
}

void	rotate_r(t_node **stack_a, t_node **stack_b)
{
	rotate_bis(stack_a);
	rotate_bis(stack_b);
	ft_putendl_fd("rrr", 1);
}

static void	reverse_rotate_bis(t_node **stack)
{
	t_node	*prev;
	t_node	*curr;

	if (!*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next)
	{
		curr = prev;
		prev = prev->next;
	}
	prev->next = *stack;
	curr->next = NULL;
	*stack = prev;
}

void	reverse_rotate_r(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_bis(stack_a);
	reverse_rotate_bis(stack_b);
	ft_putendl_fd("rrr", 1);
}
