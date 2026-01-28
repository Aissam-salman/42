/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:59:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/28 12:51:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *dup;
	int i;

	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *join;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	int i = 0;
	int j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char *clean_line(char *reading)
{
	char *stay;
	int i;
	int j;

	i = 0;
	while (reading[i] && reading[i] != '\n')
		i++;
	if (!reading[i])
		return (free(reading), NULL);
	stay = malloc(ft_strlen(reading) - i);
	if (!stay)
		return (NULL);
	i++;
	j = 0;
	while (reading[i])
		stay[j++] = reading[i++];
	stay[j] = '\0';
	free(reading);
	return (stay);
}

char *get_line(char *r)
{
	char *line;
	int i;

	if (!r || !r[0])
		return (NULL);
	i = 0;
	while (r[i] && r[i] != '\n')
		i++;
	if (r[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (r[i] && r[i] != '\n')
	{
		line[i] = r[i];
		i++;
	}
	if (r[i] == '\n')
		line[i++] = '\n'; 
	line[i] = '\0';
	return (line);
}

static int have_endl(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *read_line(char **storage, int fd)
{
	char *buffer;
	int read_bytes;
	char *tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!have_endl(storage[fd]))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), NULL);
		if (read_bytes == 0)
			break;
		buffer[read_bytes] = '\0';
		tmp = storage[fd];
		storage[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (storage[fd]);
}

char *get_next_line(int fd)
{
	static char *storage[1024];
	char *reading;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading = read_line(storage, fd);
	if (!reading)
		return (NULL);
	line = get_line(reading);
	storage[fd] = clean_line(reading);
	return (line);
}

int main(void)
{
	char *line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
