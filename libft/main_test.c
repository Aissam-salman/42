/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/09 15:14:26 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void    print_substr(const char *label, const char *s, unsigned int start, size_t len)
{
    char * res = ft_substr(s, start, len);
    printf("---------- %s --------------\n", label);
    printf("---------------------------------------\n");
    printf("ft_substr -->  \"%s\" \n", res ? res : "(NULL)");
    printf("s= %s |  start= %d |  len= %ld\n", s, start, len);
    printf("\n");
}

void    test_substr()
{
    print_substr("Base case", "Hello World", 0, 5);
    print_substr("Base case", "Hello World", 6, 5);
    print_substr("extract one caracter", "Hello World", 2, 1);
    print_substr("extract all", "Hello World", 0, 11);
    print_substr("last caracter", "Hello World", 10, 1);
    print_substr("start after slen", "Hello World", 12, 5);
    print_substr("len > slen", "Hello World", 0, 13);
    print_substr("Empty s", "", 1, 13);
    print_substr("len = 0", "Hello World", 1, 0);
    print_substr("len = 0 and start = 0", "Hello World", 0, 0);
    print_substr("start negative", "Hello World", -4, 2);
    print_substr("len negative", "Hello World", 4, -2);
    print_substr("len negative & start negative", "Hello World", -4, -2);
    print_substr("Null s", NULL, 0, 5);
    print_substr("caractere spe", "Hell# *or$d", 6, 4);
    print_substr("caractere non printable", "Hell\t \nor$d", 6, 4);
    print_substr("null terminator in the mid", "Hell\t\0\nor$d", 6, 4);
}

int main(void)
{
    test_substr();
    return (1);
}
