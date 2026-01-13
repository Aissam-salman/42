/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:49:46 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:43:51 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_index(t_node **stack)
{
	t_node	*h;
	int		i;

	if (!*stack)
	{
		return ;
	}
	i = 0;
	h = *stack;
	while (h)
	{
		h->index = i;
		h = h->next;
		i++;
	}
}

void	update_stacks_index(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
		update_index(stack_a);
	if (*stack_b)
		update_index(stack_b);
}
