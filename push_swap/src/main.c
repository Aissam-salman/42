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
#include <unistd.h>

typedef struct s_node
{
    int value;
    int cost;
    int index;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

void error_handler()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}


char **extract_params(int ac, char **av)
{
    char	**set;
    size_t	i;
    char	*tmp;

    if (ac == 2)
    {
        if (!av[1][0])
            error_handler();
        set = ft_split(av[1], ' ');
    }
    else
    {
        i = 1;
        tmp = NULL;
        while (av[i] && av[i][0])
        {
            tmp = ft_strjoin(tmp, av[i]);
	    tmp = ft_strjoin(tmp, " ");
            i++;
        }
        set = ft_split(tmp, ' ');
        free(tmp);
    }
    return (set);
}


t_node	*ft_node_new(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->value = value;
	new_node->index = index;
	return (new_node);
}

t_node	*ft_node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_node_add_back(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = ft_node_last(*lst);
		last->next = new_node;
		new_node->prev = last;
	}
}

int check_set_zero(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void init_stack(char **set)
{
	t_node *head_a;
	t_node *cur;

	int i = 0;
	head_a = NULL;
	cur = NULL;
	while (set[i])
	{
		//FIX: handle int_min and int_max
		int tr = ft_atoi(set[i]);
		if (tr == 0 && !check_set_zero(set[i]))
			error_handler();
		//FIX: handle duplicate value 
		cur = ft_node_new(tr, i);
		ft_node_add_back(&head_a, cur);
		i++;
	}

	t_node *tmp;
	tmp = head_a;
	while (tmp)
	{
		printf("set[%d] = %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
    char **set;

    if (ac < 2)
        error_handler();
    set = extract_params(ac, av);
    init_stack(set);
    // parsing args take only alpha number, no duplicate, not exceeed int max or int min
    // convert to int
    // init stack a with params in the same order , init stack b empty for now 
    // make function sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
    // start sorting stack
}
