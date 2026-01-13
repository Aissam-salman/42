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

void update_index(t_node **stack)
{
    t_node *h;
    int i;


    if (!*stack) {
        return ;
    }
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

void sort_two(t_node **stack)
{
    t_node *head;

    head = *stack;
    if (head->value < head->next->value)
	    swap(stack, "sb");
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
    if (*stack_a)
        update_index(stack_a);
    if (*stack_b)
        update_index(stack_b);
}

t_node *find_min(t_node *stack)
{
    t_node *min;

    min = stack;
    while (stack)
    {
        if (stack->value < min->value)
            min = stack;
        stack = stack->next;
    }
    return (min);
}

void find_target(t_node **stack_a, t_node **stack_b)
{
    t_node *sa;
    t_node *sb;
    t_node *min;

    if (!*stack_b)
        return ;
    sb = *stack_b;
    while (sb)
    {
        sa = *stack_a;
        min = NULL;
        while (sa)
        {
            if (sb->value < sa->value)
            {
                if (!min || min->value > sa->value)
                    min = sa;
            }
            sa = sa->next;
        }
        if (!min)
            min = find_min(*stack_a);
        sb->target = min;
        sb = sb->next;
    }
}

void    pricing(t_node **stack_a,  t_node **stack_b)
{
    t_node *hb;
    int sizeb;
    int sizea;
    int cost;

    if (!*stack_b) {
        return ;
    }

    hb = *stack_b;
    sizeb = ft_node_size(*stack_b);
    sizea = ft_node_size(*stack_a);
    while (hb)
    {
        cost = 0;
        if (hb->index <= sizeb / 2)
            cost = hb->index ;
        else
            cost = sizeb - hb->index;
        if (hb->target->index <= sizea / 2)
            cost += hb->target->index;
        else
            cost += sizea - hb->target->index;
        hb->cost = cost;
        hb = hb->next;
    }
}

int max_in_top(t_node *stack)
{
    t_node *max;

    if (!stack)
        return (0);

    max = stack;
    while (stack)
    {
        if (stack->value > max->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int max_in(t_node *stack, int value)
{
    t_node *max;

    if (!stack)
        return (0);

    max = stack;
    while (stack)
    {
        if (stack->value > value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

//FIX: reverse logic
void move_cheapest(t_node **stack_a, t_node **stack_b)
{
    t_node *cheapest;

    if (!*stack_b)
        return ;
    cheapest = find_min_cost_node(*stack_b);
    while (*stack_b && cheapest->index != 0)
    {
        if (cheapest->index < ft_node_size(*stack_b) / 2)
            rotate(stack_b, "rb");
        else
            reverse_rotate(stack_b, "rrb");
        update_index(stack_b);
        cheapest = find_min_cost_node(*stack_b);
    }
    while (*stack_a && (*stack_a)->value != cheapest->target->value)
    {
        if (cheapest->target->index > ft_node_size(*stack_a) / 2)
            reverse_rotate(stack_a, "rra");
        else
            rotate(stack_a, "ra");
        update_index(stack_a);
    }
    push_a(stack_b, stack_a);
    update_stacks_index(stack_a, stack_b);
}

void sort_turk(t_node **stack_a, t_node **stack_b)
{
    // push all i b, keep 3 val
    while (ft_node_size(*stack_a) > 4)
        push_b(stack_a,stack_b);
    sort_short(stack_a);
    update_stacks_index(stack_a, stack_b);
    while (*stack_b)
    {
        find_target(stack_a, stack_b);
        pricing(stack_a, stack_b);
        move_cheapest(stack_a, stack_b);
    }
    while (find_min(*stack_a)->value != (*stack_a)->value)
        rotate(stack_a, "ra");
}

void push_swap(t_node **stack, int size)
{
    t_node *stack_b;

    stack_b = NULL;
    if (size <= 3)
        sort_short(stack);
    else
        sort_turk(stack, &stack_b);
    if (stack_b)
        free_stack(&stack_b);
}
