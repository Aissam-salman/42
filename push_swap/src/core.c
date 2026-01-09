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
#include <unistd.h>

void swap(t_node **stack)
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
}

void rotate(t_node **stack)
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

void update_index(t_node **stack)
{
    t_node *h;
    int i;

    i = 0;
    h = *stack;
    while (h)
    {
        h->index = i;
        h = h->next;
        i++;
    }
}

void sort_short(t_node **stack)
{
    t_node *head;

    head = *stack;
     while (!check_is_stack_sorted(stack))
     {
        if (head->value > ft_node_last(head)->value)
        {

            rotate(stack);
            ft_putendl_fd("ra", 1);
        }
        else if (head->value > head->next->value)
        {
            swap(stack);
            ft_putendl_fd("sa", 1);
        }
        head = *stack;
     }
    update_index(stack);
}

void push_b(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    tmp = *stack_a;
    *stack_a = tmp->next;
    if (*stack_b)
        tmp->next = *stack_b;
    else
        tmp->next = NULL;
    *stack_b = tmp;
    ft_putendl_fd("pb", 1);
}

void push_a(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    tmp = *stack_a;
    *stack_a = tmp->next;
    if (*stack_b)
        tmp->next = *stack_b;
    else
        tmp->next = NULL;
    *stack_b = tmp;
    ft_putendl_fd("pa", 1);
}

void update_stacks_index(t_node **stack_a, t_node **stack_b)
{
    update_index(stack_a);
    update_index(stack_b);
}

void pre_sort(t_node **stack_a, t_node **stack_b)
{
    t_node *head_a;

    head_a = *stack_a;
    while (ft_node_size(head_a) > 3)
    {
        if (head_a->next && head_a->value > head_a->next->value)
            push_b(stack_a, stack_b);
        else
        {
            rotate(stack_a);
            ft_putendl_fd("ra", 1);
        }
        head_a = *stack_a;
    }
    update_stacks_index(stack_a, stack_b);
}

void find_target(t_node **stack_a, t_node **stack_b)
{
    // pour chaque element de la stack b, on cherche dans la stack a le nb qui :
    // - plus grand que le nombre B
    // - Mais le plus petit possible parmis ceux qui sont plus grand
    // = target node
    t_node *ca;
    t_node *cb;
    t_node *smallest_bigger;

    cb = *stack_b;
    while (cb)
    {
        ca = *stack_a;
        smallest_bigger = ca;
        while (ca)
        {
            if (ca->value > cb->value && cb->value < smallest_bigger->value)
                smallest_bigger = ca;
            ca = ca->next;
        }
        cb->target = smallest_bigger;
        cb = cb->next;
    }
    ft_printf("====  A ====\n");
    print_stack(*stack_a);
    ft_printf("====  B ====\n");
    print_stack_t(*stack_b);
}

void sort_turk(t_node **stack_a, t_node **stack_b)
{
    sort_short(stack_a);
    // find target node for all node in stack b
    find_target(stack_a, stack_b);

    // calculate cost move
    // choice chipest 
    // move
    // restart while stack_b not empty 
    // move min stack_a to top

}

void push_swap(t_node *stack, int size)
{
    t_node *stack_b;

    stack_b = NULL;
    if (size <= 3)
        sort_short(&stack);
    else
    {
        pre_sort(&stack, &stack_b);
        sort_turk(&stack, &stack_b);
    }
}
