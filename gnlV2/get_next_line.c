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

//TODO: keep it simple
int ft_strlen(char *s);
int find_endl_or_end_index(char *str);
char  *ft_substr(char *str, int start,int end);
char *ft_strjoin(char *s1, char *s2);

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
