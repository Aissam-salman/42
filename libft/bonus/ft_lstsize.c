/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:28:07 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 20:31:52 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"


static int ft_has_next(t_list *next)
{
    if (!next)
        return (0);
    return (1);
}

int ft_lstsize(t_list *lst)
{
    int size;

    size = 0;
    while (ft_has_next((*lst).next))
    {
        size++;
        lst++;
    }
    return (size);
}
