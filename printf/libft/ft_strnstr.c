/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:21:09 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/14 16:59:15 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	ne_len;
	size_t	i;
	size_t	j;

	ne_len = ft_strlen(needle);
	if (ne_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		if (i + ne_len > n)
			break ;
		j = 0;
		while (j < ne_len && needle[j] == haystack[i + j])
			j++;
		if (j == ne_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
