/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:51:13 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:29:53 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*dup;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*s && i < len)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	available;
	size_t	real_len;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	available = len_s - start;
	if (len > available)
		real_len = available;
	else
		real_len = len;
	return (ft_strndup(s + start, real_len));
}
