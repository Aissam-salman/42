/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:15:56 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * constant byte c.
 *
 * @param s The memory area to fill.
 * @param c The byte to fill with.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory area s.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;
	unsigned char	value_replace;

	array = (unsigned char *)s;
	value_replace = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		array[i] = value_replace;
		i++;
	}
	return (s);
}
