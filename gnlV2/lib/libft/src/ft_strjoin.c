/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:41:18 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:26:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of 's1' and 's2'.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */

static char	*fill_out(const char *s1, const char *s2, size_t lens1,
		size_t lens2)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(lens1 + lens2 + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < lens1)
		out[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < lens2)
		out[j++] = s2[i++];
	out[j] = '\0';
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	out = NULL;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	out = fill_out(s1, s2, lens1, lens2);
	return (out);
}
