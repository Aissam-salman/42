/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:01:45 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/24 19:02:37 by alamjada         ###   ########.fr       */
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

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);

    // parsing args take only alpha number, no duplicate, not exceeed int max or int min
    // convert to int
    // init stack a with params in the same order , init stack b empty for now 
    // make function sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
    // start sorting stack
}
