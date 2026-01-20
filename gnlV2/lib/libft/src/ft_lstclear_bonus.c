/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:04:52 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:20:36 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function 'del' and free(3). Finally, the pointer to the
 * list must be set to NULL.
 *
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the content of the
 * element.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		ft_lstdelone(head, del);
		head = tmp;
	}
	*lst = NULL;
}
