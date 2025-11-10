/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:44:24 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/10 17:37:23 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	while (*s)
	{
		while(*s && *s == c)
			s++;
		if (*s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*fill_word(char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	//FIX: possible error with s
	s += i;
	return (word);
}

static void	*free_array(char **arr, size_t len)
{
	while (len-- > 0)
		free(arr[len]);
	free(arr);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;
	char	**out;

	nb_words = count_words(s, c);
	out = malloc(sizeof(char *) * nb_words + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (*s)
	{
		while(*s && *s == c)
			s++;
		if (*s != c)
		{
			out[i] = fill_word((char *) s, c);
			if (!out[i])
				free_array(out, i);
		}
		i++;
	}
	return (out);
}
