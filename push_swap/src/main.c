/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:01:45 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 20:05:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* PUSH_SWAP
*
* Sorting algorithms
*
* 2 stacks : a and b
* a contains random number of unique negative and/or positive
* b empty
* >> GOAL
* sort the numbers in stack a in ascending order
* display Error\n some arguments not being integers, some arguments
  exceeding the integer limits, and/or the presence of duplicates.

  100 numbers in under 1100 operations
  500 numbers in under 8500 operations
  100 numbers in under 700 operations and 500 numbers in under 11500 operations
  100 numbers in under 1300 operations and 500 numbers in under 5500 operations
*
*
*/
#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack;
	int		len;
	char	**params;

	if (ac < 2)
		error_handler();
	params = extract_params(ac, av);
	stack = fill_stack(params);
    if (params)
    {
        free_array(params);
    }
	check_dup(stack);
	len = ft_node_size(stack);
	push_swap(&stack, len);
    free_stack(&stack);
    return (0);
}
