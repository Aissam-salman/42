/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:52:49 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:39:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	*stack = NULL;
}
