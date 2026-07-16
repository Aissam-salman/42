/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:48:47 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:26:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param size The total size of the destination buffer.
 * @return The total length of the string it tried to create: the length of
 * src.
 */

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
