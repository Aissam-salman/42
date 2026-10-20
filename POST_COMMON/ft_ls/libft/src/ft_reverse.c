/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:23:30 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 11:47:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_reverse(char *s)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = ft_strlen(s) - 1;
	while (s[index])
		ft_swap(&s[index--], &s[counter++]);
	return (s);
}
