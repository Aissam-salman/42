/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:18:04 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/19 13:01:58 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

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

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
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
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, lens2));
	if (!s2)
		return (ft_strndup(s1, lens1));
	out = NULL;
	out = fill_out(s1, s2, lens1, lens2);
	return (out);
}


char *append(char *stash, char *buffer)
{
	if (!stash)
		return (ft_strndup(buffer, ft_strlen(buffer)));
	return (ft_strjoin(stash, buffer));
}

int	have_endl(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_before_endl(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (ft_strndup(stash, i + 1));
}

char *ft_after_endl(char *stash)
{
	size_t i;
	i = 0;
	while (stash[i] != '\n')
		i++;
	return (ft_strndup(stash + i + 1, ft_strlen(stash) - i));
}

char	*get_next_line(int fd)
{
	static char *stash;
	char buffer[BUFFER_SIZE];
	int	r;
	
	stash = NULL;
	while  (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
			return (NULL);
		stash = append(stash, buffer);
		if (have_endl(stash))
		{
			char *line =  ft_before_endl(stash);
			stash = ft_after_endl(stash);
			return (line);
		}
	}
	return (stash);
}

int main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot read file.\n");
		return (-1);
	}
	printf("%s", get_next_line(fd));
	return (0);
}
