/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:48:47 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/14 16:59:01 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (size != 0)
	{
		if (src_len >= size)
			copy_len = size - 1;
		else
			copy_len = src_len;
		i = 0;
		while (i < copy_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[copy_len] = '\0';
	}
	return (src_len);
}
