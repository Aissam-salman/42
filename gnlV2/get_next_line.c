/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:46:33 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/20 19:03:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free 
// open file 
// read line
// return line
//
#include "get_next_line.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_have_endl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *ft_strdup(char *s)
{
	int len;

	if (!s)
		return (NULL);
}
//TODO: keep it simple
int ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int find_endl_or_end_index(char *str)
{
	int index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}

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

char *get_next_line(int fd)
{
	static char *storage[OPEN_MAX];
	char *buffer;
	char *tmp;
	int bytes;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	while (!is_have_endl(storage[fd]) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes == -1)
		{
			free(buffer);
			return (free(storage[fd]), storage[fd] = NULL, NULL);
		}
		else if (bytes > 0)
		{
			tmp = storage[fd];
			storage[fd] = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	if (buffer)
		free(buffer);
	if (bytes == 0)
	{
		tmp = storage[fd];
		line = storage[fd];
		free(tmp);
		storage[fd] = NULL;
		return (line);
	}
	tmp = storage[fd];
	int index_endl = find_endl_or_end_index(tmp);
	line = ft_substr(tmp, 0, index_endl);
	storage[fd] = ft_substr(tmp, index_endl + 1, ft_strlen(tmp) - ft_strlen(line));
	free(tmp);
	return (line);
}

int main()
{
	return (0);
}
