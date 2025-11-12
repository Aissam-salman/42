/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:39:44 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 20:37:19 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

#include <stdlib.h>

typedef struct  s_list
{
    void    *content;
    struct s_list   *next;
}   t_list;

t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new_node);
int ft_lstsize(t_list *lst);

#endif
