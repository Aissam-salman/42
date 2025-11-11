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

static void	*free_array(char **arr, size_t len)
{
	while (len-- > 0)
		free(arr[len]);
	free(arr);
	return (NULL);
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
	return (word);
}


static void	ft_cutstr(char const *s, char c, char **out)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while(s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			out[k] = fill_word((char *)&s[i], c);
			if (!out[k])
				free_array(out, i);
			while (s[i] && s[i] != c)
				i++;
			k++;
		}
		else 
			i++;
	}
	out[k] = NULL;
}

char **ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**out;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	out = malloc(sizeof(char *) * nb_words + 1);
	if (!out)
		return (NULL);
	if (nb_words == 0)
		out[0] = NULL;
	else 
		ft_cutstr(s, c, out);
	return (out);
}
