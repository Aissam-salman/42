/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:03:00 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/13 18:35:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/includes/libft.h"

typedef struct s_node
{
	int				value;
	int				cost;
	int				index;
	struct s_node	*next;
	struct s_node	*target;
}					t_node;

// LINKED LIST
t_node				*ft_node_new(int value, int index);
t_node				*ft_node_last(t_node *lst);
void				ft_node_add_back(t_node **lst, t_node *new_node);
int					ft_node_size(t_node *lst);
void				ft_node_delone(t_node *node);

// PARSING
char				**extract_params(int ac, char **av);
int					check_set_zero(char *s);
void				check_dup(t_node *head);
int					check_only_digit(char *str);
t_node				*fill_stack(char **params);

// UTILS
void				error_handler(void);
void				free_array(char **arr);
void				free_stack(t_node **stack);

// CORE
void				push_swap(t_node **stack, int size);

// MOVES
void				swap(t_node **stack, char *type);
void				rotate(t_node **stack, char *type);
void				reverse_rotate(t_node **stack, char *type);
void				rotate_r(t_node **stack_a, t_node **stack_b);
void				reverse_rotate_r(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_b, t_node **stack_a);
void				push_b(t_node **stack_a, t_node **stack_b);

// FINDER
int					find_min_cost_index(t_node *stack);
t_node				*find_min_cost_node(t_node *stack);
t_node				*find_node_by_index(t_node *stack, int index);
t_node				*find_min(t_node *stack);

// HANDLE INDEX
void				update_index(t_node **stack);
void				update_stacks_index(t_node **stack_a, t_node **stack_b);

// MOVE
void				swap(t_node **stack, char *type);
void				rotate(t_node **stack, char *type);
void				reverse_rotate(t_node **stack, char *type);
void				push_b(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_b, t_node **stack_a);
// MOVE2
void				rotate_r(t_node **stack_a, t_node **stack_b);
void				reverse_rotate_r(t_node **stack_a, t_node **stack_b);

// SORT SHORT
void				sort_short(t_node **stack);

#endif
