/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:31:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/27 11:33:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *get_next_line(int fd)
{
	(void)fd;
	char *out;

	out = strdup("s");
	return (out);
}

int main()
{
	char *line = get_next_line(0);
	printf("%s", line);
	free(line);
	return (0);
}
