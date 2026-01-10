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
#include <stddef.h>
#include <unistd.h>


int find_min_cost_index(t_node *stack)
{
    int min;
    int index;
    int first;

    first = 0;
    min = stack->cost;
    index = stack->index;
    while (stack)
    {
        if (stack->cost < min)
        {
            min = stack->cost;
            index = stack->index;
        }
        stack = stack->next;
    }
    return (index);
}

t_node *find_min_cost_node(t_node *stack)
{
    int i;

    i = find_min_cost_index(stack);
    while (stack)
    {
        if (stack->index == i)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

t_node *find_node_by_index(t_node *stack, int index)
{
    int i;

    i = index;
    while (stack)
    {
        if (stack->index == i)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void swap(t_node **stack, char *type)
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
    ft_putendl_fd(type, 1);
}

void rotate(t_node **stack, char *type)
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
    ft_putendl_fd(type, 1);
}

void rotate_bis(t_node **stack)
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

void rotate_r(t_node **stack_a, t_node **stack_b)
{
    rotate_bis(stack_a);
    rotate_bis(stack_b);
    ft_putendl_fd("rrr", 1);
}

void reverse_rotate(t_node **stack, char *type)
{
    t_node *prev;
    t_node *curr;

    if (!*stack || !(*stack)->next)
        return ;
    prev = *stack;
    while (prev->next)
    {
        curr = prev;
        prev = prev->next;
    }
    prev->next = *stack;
    curr->next = NULL;
    *stack = prev;
    ft_putendl_fd(type, 1);
}

void reverse_rotate_bis(t_node **stack)
{
    t_node *prev;
    t_node *curr;

    if (!*stack || !(*stack)->next)
        return ;
    prev = *stack;
    while (prev->next)
    {
        curr = prev;
        prev = prev->next;
    }
    prev->next = *stack;
    curr->next = NULL;
    *stack = prev;
}

void reverse_rotate_r(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate_bis(stack_a);
    reverse_rotate_bis(stack_b);
    ft_putendl_fd("rrr", 1);
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

int check_is_stack_sorted_dec(t_node **stack)
{
    t_node *head;

    head = *stack;
    while (head)
    {
        if (head->next && head->value < head->next->value)
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
            rotate(stack, "ra");
        else if (head->value > head->next->value)
            swap(stack, "sa");
        head = *stack;
     }
    update_index(stack);
}

void sort_short_dec(t_node **stack)
{
    t_node *head;

    head = *stack;
     while (!check_is_stack_sorted_dec(stack))
     {
        if (head->value < head->next->value)
            rotate(stack, "rb");
        else if (head->value < head->next->value)            
            swap(stack, "sb");
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

void push_a(t_node **stack_b, t_node **stack_a)
{
    t_node *tmp;

    tmp = *stack_b;
    *stack_b = tmp->next;
    if (*stack_a)
        tmp->next = *stack_a;
    else
        tmp->next = NULL;
    *stack_a = tmp;
    ft_putendl_fd("pa", 1);
}

void update_stacks_index(t_node **stack_a, t_node **stack_b)
{
    update_index(stack_a);
    update_index(stack_b);
}


int find_min(t_node *stack)
{
    t_node *min;

    min = stack;
    while (stack)
    {
        ft_printf("%stack= %d, min= %d\n", stack->value, min->value);
        if (stack->value > min->value)
            min = stack;
        stack = stack->next;
    }
    min->next = NULL;
    return (min->index);
}

int check_if_small(int minp, t_node **stack_b)
{
    t_node *h;

    h = *stack_b;
    while (h)
    {
        if (h->value > minp)
            return (0);
        h = h->next;
    }
    return (1);
}

void free_node(t_node *node)
{
    t_node *tmp;

    tmp = node;
    while (tmp)
    {
        free(node);
        tmp = tmp->next;
    }
    free(node);
    node = NULL;
}

// FIX: rewrite all
void find_target(t_node **stack_a, t_node **stack_b)
{
    // t_node *ca;
    // t_node *cb;
    // t_node *smallest_bigger;
    // t_node *cb_copy;
    //
    // ca = *stack_a;
    // smallest_bigger = NULL;
    // while (ca)
    // {
    //     cb = *stack_b;
    //     while (cb)
    //     {
    //         if (cb->value > ca->value)
    //         {
    //             cb_copy = cb;
    //             cb_copy->next = NULL;
    //             ft_node_add_back(&smallest_bigger, cb_copy);
    //         }
    //         cb = cb->next;
    //     }
    //     if (!smallest_bigger )
    //     {
    //         int index_min = find_min(cb);
    //         ca->target = find_node_by_index(*stack_b, index_min);
    //     }
    //     else
    //     {
    //         ft_printf("smallestpb: %d\n", smallest_bigger->value);
    //         print_stack_t(*stack_a);
    //         int index_min = find_min(smallest_bigger);
    //         ca->target = find_node_by_index(*stack_b, index_min);
    //         ft_printf("ici\n");
    //         ft_printf("val= %d, target = %d\n",ca->value, ca->target);
    //     }
    //     ca = ca->next;
    // }
}

void    pricing(t_node **stack_a,  t_node **stack_b)
{
    t_node *ha;
    int sizeb;
    int sizea;
    int cost;

    ha = *stack_a;
    sizea = ft_node_size(*stack_a);
    sizeb = ft_node_size(*stack_b);
    while (ha)
    {
        if (ha->index < sizea / 2)
            cost = ha->index;
        else 
            cost = sizea - ha->index;
        if (ha->target->index < sizeb / 2)
            cost += ha->target->index;
        else 
            cost += sizeb - ha->target->index;
        ha->cost = cost;
        ha = ha->next;
    }
}



void move_cheapest(t_node **stack_a, t_node **stack_b)
{
    t_node *node_cheapest;

    node_cheapest = find_min_cost_node(*stack_a);
    while(node_cheapest->index != 0)
    {
        if (node_cheapest->index < ft_node_size(*stack_a) / 2)
            rotate(stack_a, "ra");
        else
            reverse_rotate(stack_a, "rra");
        update_stacks_index(stack_a, stack_b);
        while ((*stack_b)->value != node_cheapest->target->value)
        {
            if (node_cheapest->target->index < ft_node_size(*stack_b) / 2)
                rotate(stack_b, "rb");
            else if (node_cheapest->target->index > ft_node_size(*stack_b) / 2)
                reverse_rotate(stack_b, "rrb");
            update_index(stack_b);
        }
        update_stacks_index(stack_a, stack_b);
    }
    push_b(stack_a, stack_b);
    rotate(stack_b, "rb");
    update_stacks_index(stack_a, stack_b);
}

void sort_turk(t_node **stack_a, t_node **stack_b)
{
    sort_short_dec(stack_b);
    while (*stack_a)
    {
        find_target(stack_a, stack_b);
        ft_printf("la\n");
        pricing(stack_a, stack_b);
        move_cheapest(stack_a, stack_b);
    }
    //NOTE: move min stack_a to top
}

void push_swap(t_node *stack, int size)
{
    t_node *stack_b;

    stack_b = NULL;
    if (size <= 3)
        sort_short(&stack);
    else
    {
        push_b(&stack, &stack_b);
        push_b(&stack, &stack_b);
        push_b(&stack, &stack_b);
        update_stacks_index(&stack, &stack_b);
        sort_turk(&stack, &stack_b);
    }
}
