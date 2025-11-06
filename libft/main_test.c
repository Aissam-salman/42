/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/06 21:23:52 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(void)
{
	// char buffer[] = "This is a test of the memset function";
	//
	// printf("Before:%s\n", buffer);
	// ft_bzero(buffer, 2);
	// printf("After:%s\n", buffer + 2);
	//
	// char dest[10];
	// char *src = NULL;
	// ft_memcpy(dest, src, 1);
	// printf("%s", dest);
	//
	// char dest[10];
	// char *src = "foo";
	// ft_memmove(dest, 0, 0);
	// printf("%s", dest);
	//
	int size  = 3;
	char string[] = "Hello";
    char buffer[2] = "xx";
    int r = ft_strlcpy(buffer, string, size);
    int len = ft_strlen(buffer);
    printf("Source: '%s', size: %d, dest: '%s', len dest: %d, return: %d\n",
           string, size, buffer, len, r);
	return (0);
}
