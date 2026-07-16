/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:01:45 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/21 10:51:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{

	t_node	*stack;
	int		len;
	char	**params;

	if (ac < 2)
		return (0);
	params = extract_params(ac, av);
	if (!params || !*params)
		error_handler();
	stack = fill_stack(params);
	if (params)
		free_array(params);
	check_dup(stack);
	len = ft_node_size(stack);
	push_swap(&stack, len);
	free_stack(&stack);
	return (0);
}
