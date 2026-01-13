/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:40:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:40:26 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **stack, char *type)
{
	t_node	*head;
	t_node	*nxt;
	t_node	*nxt2;

	head = *stack;
	nxt = head->next;
	nxt2 = nxt->next;
	head->next = nxt2;
	nxt->next = head;
	*stack = nxt;
	ft_putendl_fd(type, 1);
}

void	rotate(t_node **stack, char *type)
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
	ft_putendl_fd(type, 1);
}

void	reverse_rotate(t_node **stack, char *type)
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
	ft_putendl_fd(type, 1);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	*stack_a = tmp->next;
	if (*stack_b)
		tmp->next = *stack_b;
	else
		tmp->next = NULL;
	*stack_b = tmp;
	ft_putendl_fd("pb", 1);
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_b;
	*stack_b = tmp->next;
	if (*stack_a)
		tmp->next = *stack_a;
	else
		tmp->next = NULL;
	*stack_a = tmp;
	ft_putendl_fd("pa", 1);
}
