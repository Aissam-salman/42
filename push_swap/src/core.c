/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:03:39 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 20:09:26 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap_a(t_node **stack)
{
    t_node *head;
    t_node *nxt;
    t_node *nxt2;

    head = *stack;
    nxt = head->next;
    nxt2 = nxt->next;

    head->next = nxt2;
    nxt->next = head;
    *stack = nxt;

    //TODO: fn to change index after move
}

void sort_short(t_node **stack, int size)
{
    t_node *head;
    (void)size;

    head = *stack;
    // if first > last rotate_a
    // check if sorted ? 
    //     yes return 
    //     no continue
    if (head->value > head->next->value)
        swap_a(stack);
}

void push_swap(t_node *stack, int size)
{
    // handle diff sort with size
    ft_printf("==== BEFORE SORT ====\n");
    print_stack(stack);
    ft_printf("len= %d\n", size);
    if (size <= 3)
        sort_short(&stack, size);
    ft_printf("==== AFTER SORT ====\n");
    print_stack(stack);
}
