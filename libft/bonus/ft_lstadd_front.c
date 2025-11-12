/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:11 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 20:27:15 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

void    ft_lstadd_front(t_list **lst, t_list *new_node)
{
    new_node->next = *lst;
}
