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
#include <stdio.h>
#include <stdlib.h>

// typedef struct s_node
// {
//     int value;
//     struct s_node next;
//     struct s_node prev;
//     int cost;
//     int index;
// }   t_node;

void error_handler()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

char *ft_join_w_space(char *tmp, char *str)
{
    int len_t;
    int  len_s;
    char *out;
    int i;
    int  j;

    if (!tmp && !str)
        return (NULL);
    if (!tmp)
        return (ft_strdup(str));
    if (!str)
        return (ft_strdup(tmp));
    len_t = ft_strlen(tmp);
    len_s = ft_strlen(str);
    out = malloc(len_t + len_s + 1);
    if (!out)
        return (NULL);
}

int main(int ac, char **av)
{
    char **set;
    // t_node *head;
    size_t i;
    char *tmp;

    if (ac < 2)
        error_handler();
    if (ac == 2)
    {
        if (!av[1][0])
            error_handler();
        set = ft_split(av[1], ' ');
    }
    else
    {
        i = 0;
        tmp = NULL;
        while (av[i] && av[i][0])
        {
            tmp = ft_join_w_space(tmp, av[1]);
            i++;
        }
        set = ft_split(tmp, ' ');
        free(tmp);
    }

    for (int i = 0; set[i]; i++) {
        printf("set[%d] = %s", i, set[i]);
    }

    // t_node *stack_a = init_stack(set);
    // t_node *stack_b = init_stack(0);
    

    // parsing args take only alpha number, no duplicate, not exceeed int max or int min
    // convert to int
    // init stack a with params in the same order , init stack b empty for now 
    // make function sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
    // start sorting stack
}
