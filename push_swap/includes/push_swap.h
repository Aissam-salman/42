/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:03:00 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 20:04:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/includes/libft.h"

typedef struct s_node
{
    int value;
    int cost;
    int index;
    struct s_node *next;
}   t_node;

// LINKED LIST
t_node	*ft_node_new(int value, int index);
t_node	*ft_node_last(t_node *lst);
void	ft_node_add_back(t_node **lst, t_node *new_node);
void    print_stack(t_node *stack);
int	ft_node_size(t_node *lst);

// PARSING
char **extract_params(int ac, char **av);
int check_set_zero(char *s);
void    check_dup(t_node *head);
int check_only_digit(char *str);
t_node *fill_stack(char **params);

// UTILS
void error_handler();

// CORE
void push_swap(t_node *stack, int size);

#endif
