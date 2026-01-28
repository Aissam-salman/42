/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:13:48 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/28 11:58:33 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 42

int  have_endl(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *dup;
	int i;

	if (!str)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while(str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *join;
	int i;
	int j;
	
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
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

char *get_line(char *reading)
{
	char *line;
	int i;

	if (!reading || !reading[0])
		return (NULL);
	i = 0;
	while (reading[i] && reading[i] != '\n')
		i++;
	if (reading[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (reading[i] && reading[i] != '\n')
	{
		line[i] = reading[i];
		i++;
	}
	if (reading[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *clean_stay(char *reading)
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
	storage[fd] = clean_stay(reading);
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
