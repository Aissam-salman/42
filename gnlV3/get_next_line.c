/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:40:21 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/27 19:35:01 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int have_endl(char *line)
{
	int i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int  ft_strlen(char *s)
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
	int len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
	char  *join;
	int lens1;
	int lens2;
	int i;
	int j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	join = malloc(lens1 + lens2 + 1);
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
		{
			free(buffer);
			free(storage[fd]);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		tmp = storage[fd];
		storage[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (storage[fd]);
}

char *clean_storage(char *storage)
{
	int i;

	i = 0;
	while (storage[i] != '\n')
		i++;
	int j = i;
	while(storage[j])
		j++;
	int len = j - i;
	char *new_storage = malloc(len + 1);
	if (!new_storage)
		return (NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	storage = NULL;
	return (new_storage);
}

char *extract_before_endl(char *storage)
{
	char *line;
	int i;

	i = 0;
	while (storage[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	static char *storage[1024];
	char *reading;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	reading = read_line(storage, fd);
	line = extract_before_endl(reading);
	storage[fd] = clean_storage(reading);
	if (!storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
	return (line);
}

int main(void)
{
	char *line;

	int fd = open("test", O_RDONLY);
	if (fd < 0)
		exit(2);
	while((line = get_next_line(fd) ) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
