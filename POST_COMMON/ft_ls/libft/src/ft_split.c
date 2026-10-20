/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:44:24 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	free_array(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

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
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	ft_cutstr(char **out, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
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
				return (0);
			}
			s += len;
			i++;
		}
	}
	out[i] = NULL;
	return (1);
}

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's'
 * using the character 'c' as a delimiter. The array must be ended by a NULL
 * pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 * allocation fails.
 */

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**out;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	out = malloc(sizeof(char *) * (nb_words + 1));
	if (!out)
		return (NULL);
	if (!ft_cutstr(out, s, c))
		return (NULL);
	return (out);
}
