/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:21:09 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:29:53 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string needle in
 * the string haystack, where not more than n characters are searched.
 * Characters that appear after a '\\0' character are not searched.
 *
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param n The maximum number of characters to search.
 * @return If needle is an empty string, haystack is returned; if needle occurs
 * nowhere in haystack, NULL is returned; otherwise a pointer to the first
 * character of the first occurrence of needle is returned.
 */

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
