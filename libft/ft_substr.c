/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:51:13 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/09 15:13:17 by salman           ###   ########.fr       */
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

  if (!s)
    return (NULL);
  len_s = ft_strlen(s);
  if (start >= len_s)
    return (ft_strdup(""));
  out = ft_strndup(s + start, len);
  return (out);
}
