/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:09:17 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:29:53 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Allocates and returns a copy of 's1' with the characters specified in
 * 'set' removed from the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	start = 0;
	end = (size_t)ft_strlen(s1);
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	out = ft_substr(s1, start, end - start);
	return (out);
}
