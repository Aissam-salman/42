/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:54:07 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:42:47 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*extract_line(char **item)
{
	char	*line;
	size_t	i;
	char	*old;

	if (!item || !*item)
		return (NULL);
	i = 0;
	while ((*item)[i] && (*item)[i] != '\n')
		i++;
	line = ft_strndup(*item, i + 1);
	if (!line)
		return (NULL);
	if ((*item)[i] && (*item)[i + 1])
	{
		old = *item;
		*item = ft_substr(*item, (int)i + 1, ft_strlen(*item) - (i + 1));
		free(old);
	}
	else
	{
		free(*item);
		*item = NULL;
	}
	return (line);
}

static char	*append(char **lst, char *buf, int rd)
{
	char	*old;
	char	*temp;

	buf[rd] = '\0';
	old = *lst;
	temp = ft_strjoin(*lst, buf);
	if (!temp)
	{
		free(buf);
		if (*lst)
		{
			free(*lst);
			*lst = NULL;
		}
		buf = NULL;
		return (NULL);
	}
	free(old);
	*lst = temp;
	free(buf);
	old = NULL;
	buf = NULL;
	return (*lst);
}

char	*check_read(char **lst, char *buf, int rd)
{
	char	*temp;

	if (rd < 0)
	{
		if (*lst)
		{
			free(*lst);
			*lst = NULL;
		}
		return (free(buf), NULL);
	}
	if (rd == 0)
	{
		if (*lst)
		{
			temp = ft_strndup(*lst, ft_strlen(*lst));
			free(*lst);
			*lst = NULL;
			free(buf);
			buf = NULL;
			return (temp);
		}
		return (free(buf), NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*lst[4096];
	char		*buf;
	int			read_bytes;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (lst[fd] && ft_strchr(lst[fd], '\n'))
			return (extract_line(&lst[fd]));
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		temp = check_read(&lst[fd], buf, read_bytes);
		if (read_bytes <= 0)
			return (lst[fd] = NULL, temp);
		if (!append(&lst[fd], buf, read_bytes))
			return (NULL);
	}
	return (NULL);
}
