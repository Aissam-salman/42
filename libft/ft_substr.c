/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:51:13 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 16:19:31 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_strndup(const char *s, size_t len) {
  size_t i;
  char *dup;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*s && i < len)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t len_s;
  char *out;
  size_t real_len;

	if (!s)
		return (NULL);
	if ((int)len < 0)
		return (ft_strdup(""));
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	real_len = len;
	if (start + len > len_s)
		real_len = len_s - start;
	out = ft_strndup(s + start, real_len);
	return (out);
}
