/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:48:35 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/10 21:40:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	char buf[4096];
	char len;
	char c;
	int i;
	
	if (ac != 2)
		return (1);
	i = 0;
	while (read(0, &c, 1) > 0)
		buf[i++] = c;
	buf[i] = 0;
	len = ft_strlen(av[1]);
	i = 0;
	while (buf[i])
	{
		if (ft_strncmp(&buf[i], av[1], len) == 0)
		{
			for (int j = 0; j < len; j++) {
				write(1, "*", 1);
			}
			i += len;
		}
		else
			write(1, &buf[i++], 1);
	}
	return (0);
}
