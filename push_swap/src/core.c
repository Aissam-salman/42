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
    ft_putendl_fd("sa", 1);
}

void rotate_a(t_node **stack)
{
    t_node *head;
    t_node *nxt;
    t_node *last;

    head = *stack;
    nxt = head->next;
    last = ft_node_last(head);
    last->next = head;
    head->next = NULL;
    *stack = nxt;
    ft_putendl_fd("ra", 1);
}

int check_is_stack_sorted(t_node **stack)
{
    t_node *head;

    head = *stack;
    while (head)
    {
        if (head->next && head->value > head->next->value)
            return (0);
        head = head->next;
    }
    return (1);
}

void sort_short(t_node **stack)
{
    t_node *head;

    head = *stack;
     while (!check_is_stack_sorted(stack))
     {
        if (head->value > ft_node_last(head)->value)
            rotate_a(stack);
        else if (head->value > head->next->value)
            swap_a(stack);
        head = *stack;
     }
    //TODO: fn to change index after move
}

// void pre_sort(t_node **stack);

void sort_turk(t_node **stack);

void push_swap(t_node *stack, int size)
{
    // handle diff sort with size
    ft_printf("==== BEFORE SORT ====\n");
    print_stack(stack);
    if (size <= 3)
        sort_short(&stack);
    else if (size <= 10)
        sort_turk(&stack);
    // else 
    // {
    //     pre_sort(&stack);
    //     sort_turk(&stack);
    // }
    ft_printf("==== AFTER SORT ====\n");
    print_stack(stack);
}
