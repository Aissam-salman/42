/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:21:23 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/20 21:03:28 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*s && i < len)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

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

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	out = NULL;
	out = fill_out(s1, s2, ft_strlen(s1), ft_strlen(s2));
	return (out);
}

char *append(char *stash, char *buffer)
{
	if (!stash)
		return (ft_strndup(buffer, ft_strlen(buffer)));
	return (ft_strjoin(stash, buffer));
}
