/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:49:46 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/07 20:01:25 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**extract_params(int ac, char **av)
{
	char	**set;
	size_t	i;
	char	*tmp;
    char *old;

	if (ac == 2)
	{
		if (!av[1][0])
			error_handler();
		return (ft_split(av[1], ' '));
	}
    i = 1;
    tmp = NULL;
    while (av[i] && av[i][0])
    {
        old = tmp;
        tmp = ft_strjoin(tmp, av[i]);
        free(old);
        old = tmp;
        tmp = ft_strjoin(tmp, " ");
        free(old);
        i++;
    }
    set = ft_split(tmp, ' ');
    free(tmp);
	return (set);
}

int	check_set_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	check_dup(t_node *head)
{
	t_node	*tmp_next;

	while (head)
	{
		tmp_next = head->next;
		while (tmp_next)
		{
			if (head->value == tmp_next->value)
            {
                free_stack(&head);
				error_handler();
            }
			tmp_next = tmp_next->next;
		}
		head = head->next;
	}
}

int	check_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*fill_stack(char **params)
{
	t_node	*stack;
	t_node	*cur;
	int		i;
	int		tr;

	i = 0;
	stack = NULL;
	cur = NULL;
	while (params[i])
	{
		tr = ft_atoi(params[i]);
		if (tr == 0 && !check_set_zero(params[i]))
        {
            free_stack(&stack);
            free_array(params);
			error_handler();
        }
		else if (!check_only_digit(params[i]))
        {
            free_stack(&stack);
            free_array(params);
			error_handler();
        }
		cur = ft_node_new(tr, i);
		ft_node_add_back(&stack, cur);
		i++;
	}
	return (stack);
}
