/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:12:43 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:20:36 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content of
 * each element.
 *
 * @param lst The beginning of the list.
 * @param f The address of the function to apply to each element.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*head;

	if (!lst || !f)
		return ;
	head = lst;
	while (head)
	{
		f(head->content);
		head = head->next;
	}
}
