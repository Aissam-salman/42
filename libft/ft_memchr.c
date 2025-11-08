/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:27:20 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 14:45:09 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;
	size_t	i;

	scpy = (unsigned char *) s;
	ccpy = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (scpy[i] == ccpy)
			return (scpy + i);
		i++;
	}
	return (0);
}
