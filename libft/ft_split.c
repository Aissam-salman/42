/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:44:24 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 20:46:11 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}

static size_t word_len(char const *s, char c)
{
    size_t len;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    return (len);
}


static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while(*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_cutstr(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**out;

	i = 0;
	out = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!out)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			out[i] = ft_substr(s, 0, len);
			if (!out[i])
			{
				free_array(out, i);
				return (NULL);
			}
			s += len;
			i++;
		}
	}
	out[i] = NULL;
	return (out);
}

char **ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**out;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	out = malloc(sizeof(char *) * (nb_words + 1));
	if (!out)
		return (NULL);
	out = ft_cutstr(s, c);
	return (out);
}
