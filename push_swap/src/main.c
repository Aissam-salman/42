/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:01:45 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 19:57:42 by alamjada         ###   ########.fr       */
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

void init_stack(char **set)
{
    t_node *stack;
    int len;

    stack = fill_stack(set);
    check_dup(stack);
    len = ft_node_size(stack);
    print_stack(stack);
    ft_printf("len: %d\n", len);
    // push_swap(head, len);
}

int main(int ac, char **av)
{
    char **params;

    if (ac < 2)
        error_handler();
    params = extract_params(ac, av);
    init_stack(params);
    // make function sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
    // start sorting stack
}
