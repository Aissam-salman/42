/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:48:47 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/06 21:25:04 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*original_src;
	size_t	counter;

	original_src = src;
	counter = size;
	if (counter != 0)
	{
		while (--counter != 0)
		{
			*dst++ = *src++;
			if (*dst == '\0' || *src == '\0')
				break;
		}
	}
	if (counter == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - original_src - 1);
}
