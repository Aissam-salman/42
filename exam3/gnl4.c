#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 20

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

	if (!str)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	int i = 0;
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

char *clean_line(char *rd)
{
	char *dest;
	int i;

	i = 0;
	while (rd[i] && rd[i] != '\n')
		i++;
	if (!rd[i])
		return (free(rd), NULL);
	dest = malloc(ft_strlen(rd) - i);
	if (!dest)
		return (free(rd), NULL);
	i++;
	int j = 0;
	while (rd[i])
		dest[j++] = rd[i++];
	dest[j] = '\0';
	free(rd);
	return (dest);
}

char *get_line(char *rd)
{
	char *line;
	int i;

	i = 0;
	if (!rd || !rd[i])
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(rd), NULL);
	i = 0;
	while (rd[i] && rd[i] != '\n')
	{
		line[i] = rd[i];
		i++;
	}
	if (rd[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static int have_endl(char *str)
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
	char *buf;
	int rb;
	char *tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!have_endl(store[fd]))
	{
		rb = read(fd, buf, BUFFER_SIZE);
		if (rb < 0)
			return (free(buf), NULL);
		if (rb == 0)
			break;
		buf[rb] = '\0';
		tmp = store[fd];
		store[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (store[fd]);
}

char *get_next_line(int fd)
{
	static char *store[1024];
	char *rd;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = read_line(store, fd);
	if (!rd)
		return (rd);
	line = get_line(rd);
	store[fd] = clean_line(rd);
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
