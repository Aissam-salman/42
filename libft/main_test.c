/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/07 19:11:08 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*#include <bsd/string.h>
#include <stdlib.h>
void test_strlcat(const char *label, const char *dst_init, const char *src, size_t size)
{
    char dst_real[100];
    char dst_ft[100];
    size_t ret_real, ret_ft;

    // copies initiales identiques
    memset(dst_real, 0, sizeof(dst_real));
    memset(dst_ft, 0, sizeof(dst_ft));
    strncpy(dst_real, dst_init, sizeof(dst_real) - 1);
    strncpy(dst_ft, dst_init, sizeof(dst_ft) - 1);

    ret_real = strlcat(dst_real, src, size);
    ret_ft   = ft_strlcat(dst_ft, src, size);

    printf("---- %s ----\n", label);
    printf("size = %zu\n", size);
    printf("src  = \"%s\"\n", src);
    printf("Avant  : \"%s\"\n", dst_init);
    printf("strlcat -> ret=%zu | dst=\"%s\"\n", ret_real, dst_real);
    printf("ft_strlcat -> ret=%zu | dst=\"%s\"\n", ret_ft, dst_ft);
    printf("\n");
}

void	data_ft_strlcat(void)
{
    test_strlcat("size = 0", "Hello", "World", 0);
    test_strlcat("size = ft_strlen(dst)", "Hello", "World", ft_strlen("Hello"));
    test_strlcat("size = ft_strlen(dst)+1", "Hello", "World", ft_strlen("Hello") + 1);
    test_strlcat("size = ft_strlen(dst)+10", "Hello", "World", ft_strlen("Hello") + 10);
    test_strlcat("src vide", "Hello", "", 20);
    test_strlcat("dst vide", "", "World", 20);
    test_strlcat("dst presque plein (1 libre)", "Hell", "oWorld", 6);
}

void	test_ft_toupper(void)
{
	printf("TOUPPER\n");
	int c = 'C';
	printf("'%c' avant;\n", c);
	c = ft_toupper(c);
	printf("'%c' rien ne change \n", c);
	int a = 'a';
	printf("'%c' avant;\n", a);
	a = ft_toupper(a);
	printf("'%c' apres;\n\n", a);
}

void	test_ft_tolower(void)
{
	printf("TOLOWER\n");
	int c = 'c';
	printf("'%c' avant;\n", c);
	c = ft_tolower(c);
	printf("%c rien ne change \n", c);
	int a = 'A';
	printf("'%c' avant;\n", a);
	a = ft_tolower(a);
	printf("'%c' apres;\n\n", a);
}
*/
int main(void)
{ 
	// data_ft_strlcat();
	// test_ft_toupper();
	// test_ft_tolower();
	return (0);
}
