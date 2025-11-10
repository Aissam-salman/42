/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/10 13:42:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// void print_substr(const char *label, const char *s, unsigned int start, size_t len, const char *expected)
// {
//     char *res = ft_substr(s, start, len);
//
//     printf("---------- %s --------------\n", label);
//     printf("s = \"%s\" | start = %u | len = %zu\n", s ? s : "(NULL)", start, len);
//     printf("ft_substr  --> \"%s\"\n", res ? res : "(NULL)");
//     printf("expected   --> \"%s\"\n", expected ? expected : "(NULL)");
//
//     // ✅ Vérification automatique
//     int ok;
//     if (expected == NULL && res == NULL)
//         ok = 1;
//     else if (expected == NULL || res == NULL)
//         ok = 0;
//     else
//         ok = strcmp(res, expected) == 0;
//     printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
//     free(res);
// }
//
// void    test_substr()
// {
// 	print_substr("Base case", "Hello World", 0, 5, "Hello");
// 	print_substr("Base case 2", "Hello World", 6, 5, "World");
// 	print_substr("extract one caracter", "Hello World", 2, 1, "l");
// 	print_substr("extract all", "Hello World", 0, 11, "Hello World");
// 	print_substr("last caracter", "Hello World", 10, 1, "d");
// 	print_substr("start after slen", "Hello World", 12, 5, "");
// 	print_substr("len > slen", "Hello World", 0, 13, "Hello World");
// 	print_substr("Empty s", "", 1, 13, "");
// 	print_substr("len = 0", "Hello World", 1, 0, "");
// 	print_substr("len = 0 and start = 0", "Hello World", 0, 0, "");
// 	print_substr("start negative", "Hello World", -4, 2, "");
// 	print_substr("len negative", "Hello World", 4, -2, "");
// 	print_substr("len negative & start negative", "Hello World", -4, -2, "");
// 	print_substr("Null s", NULL, 0, 5, NULL);
// 	print_substr("caractere spe", "Hell# *or$d", 4, 4, "# *o");
// 	print_substr("caractere non printable", "Hell\t \nor$d", 6, 4, "\nor$");
// 	print_substr("null terminator in the mid", "Hell\t\0\nor$d", 6, 4, "");
// }

// void print_strjoin(const char *label, const char *s1, const char *s2, const char *expected)
// {
//     char *res = ft_strjoin(s1, s2);
//
//     printf("---------- %s --------------\n", label);
//     printf("s1 = \"%s\" | s2 = \"%s\" \n", s1 ? s1 : "(NULL)", s2 ? s2 : "(NULL)");
//     printf("ft_strjoin  --> \"%s\"\n", res ? res : "(NULL)");
//     printf("expected   --> \"%s\"\n", expected ? expected : "(NULL)");
//
//     // ✅ Vérification automatique
//     int ok;
//     if (expected == NULL && res == NULL)
//         ok = 1;
//     else if (expected == NULL || res == NULL)
//         ok = 0;
//     else
//         ok = strcmp(res, expected) == 0;
//     printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
//     free(res);
// }
//
// void    test_strjoin()
// {
// 	print_strjoin("Base case", "Hello", " World", "Hello World");
// 	print_strjoin("Base case", "foo", "Boo", "fooBoo");
// 	print_strjoin("Empty s1", "", "Boo", "Boo");
// 	print_strjoin("Empty s2", "foo", "", "foo");
// 	print_strjoin("Empty s1 & s2", "", "", "");
// 	print_strjoin("Null s1", NULL, "Boo", "Boo");
// 	print_strjoin("Null s2", "foo", NULL, "foo");
// 	print_strjoin("Null s1 & s2", NULL, NULL, NULL);
// 	print_strjoin("Caracter spe", "fo#", "*(o", "fo#*(o");
// 	print_strjoin("Caracter non printable", "foo \n", "B\roo", "foo \nB\roo");
// }

void print_strtrim(const char *label, const char *s1, const char *set, const char *expected)
{
    char *res = ft_strtrim(s1, set);

    printf("---------- %s --------------\n", label);
    printf("s1 = \"%s\" | set = \"%s\" \n", s1 ? s1 : "(NULL)", set ? set : "(NULL)");
    printf("ft_strtrim  --> \"%s\"\n", res ? res : "(NULL)");
    printf("expected   --> \"%s\"\n", expected ? expected : "(NULL)");

    // ✅ Vérification automatique
    int ok;
    if (expected == NULL && res == NULL)
        ok = 1;
    else if (expected == NULL || res == NULL)
        ok = 0;
    else
        ok = strcmp(res, expected) == 0;
    printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
    free(res);
}

void    test_strtrim()
{
	print_strtrim("Base", "   Hello World   ", " ", "Hello World");
	print_strtrim("Tab & newline", "\t\nHello\n\t", "\n\t", "Hello");
	print_strtrim("Mixed set", "***Hello***", "*", "Hello");
	print_strtrim("Mix debut et fin", "--Hello--World--", "-", "Hello--World");
	print_strtrim("No trim", "Hello", " ", "Hello");
	print_strtrim("Set empty", "Hello", "", "Hello");
	print_strtrim("S1 empty", "", " ", "");
	print_strtrim("All trim", "aaaaa", "a", "");
	print_strtrim("Cara mix", "abcHelloabc", "abc", "Hello");
	print_strtrim("Cara spe", "$$Hell#o$$", "$#", "Hell#o");
	print_strtrim("Trim space and tab", "  \tHello\t  ", " \t", "Hello");
	print_strtrim("s1 = NULL", NULL, " ", NULL);
	print_strtrim("set = NULL", "Hello", NULL, NULL);
	print_strtrim("Unicode", "ééBonjouré", "é", "Bonjour");
	print_strtrim("non printable", "\nHello\t", "\n\t", "Hello");
	print_strtrim("set= 'Hello'", "HelloHello", "Hello", "");
	print_strtrim("Trim before", "    Hello", " ", "Hello");
	print_strtrim("Trim after", "Hello    ", " ", "Hello");
}

int main(void)
{
    test_strtrim();
    return (1);
}
