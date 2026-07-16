/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:58:14 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/07 19:02:44 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 24

int ft_strlen(char *s)
{
	int i = 0;
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
	while (str[i])
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

char *clean_line(char *re)
{
	char *rest;
	int i;
	int j;

	i = 0;
	while (re[i] && re[i] != '\n')
		i++;
	if (!re[i])
		return (free(re), NULL);
	rest = malloc(ft_strlen(re) - i);
	if (!rest)
		return (free(re), NULL);
	i++;
	j = 0;
	while (re[i])
		rest[j++] = re[i++];
	rest[j] = '\0';
	free(re);
	return (rest);
}

char *get_line(char *re)
{
	char *line;
	int i;

	i = 0;
	if (!re || !re[i])
		return (NULL);
	while (re[i] && re[i] != '\n')
		i++;
	if (re[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (re[i] && re[i] != '\n')
	{
		line[i] = re[i];
		i++;
	}
	if (re[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}


int have_endl(char *str)
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

char *read_line(char **store, int fd)
{
	char *buffer;
	int read_b;
	char *tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!have_endl(store[fd]))
	{
		read_b = read(fd, buffer, BUFFER_SIZE);
		if (read_b < 0)
			return (free(buffer), NULL);
		if (read_b == 0)
			break;
		buffer[read_b] = '\0';
		tmp = store[fd];
		store[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (store[fd]);
}

char	*get_next_line(int fd)
{
	static char *store[1024];
	char *reading;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading = read_line(store, fd);
	if (!reading)
		return (NULL);
	line = get_line(reading);
	store[fd] = clean_line(reading);
	return (line);
}

int	main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (1);
}
