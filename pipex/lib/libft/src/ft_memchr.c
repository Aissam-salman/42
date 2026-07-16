/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:27:20 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:21:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char.
 *
 * @param s The memory area to scan.
 * @param c The character to scan for.
 * @param n The number of bytes to scan.
 * @return A pointer to the matching byte or NULL if the character does not
 * occur in the given memory area.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;
	size_t			i;

	scpy = (unsigned char *)s;
	ccpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (scpy[i] == ccpy)
			return (scpy + i);
		i++;
	}
	return (0);
}
