/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 15:41:09 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

/*#include <bsd/string.h>
void test_strlcat(const char *label, const char *dst_init, const char *src,
size_t size)
{
    char dst_real[100];
    char dst_ft[100]; size_t ret_real, ret_ft;

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
    test_strlcat("size = ft_strlen(dst)+1", "Hello", "World", ft_strlen("Hello")
+ 1); test_strlcat("size = ft_strlen(dst)+10", "Hello", "World",
ft_strlen("Hello") + 10); test_strlcat("src vide", "Hello", "", 20);
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

void test_strchr(const char *label, const char *s, int c)
{
    char *ret_real = strrchr(s, c);
    char *ret_ft   = ft_strrchr(s, c);

    printf("---- %s ----\n", label);
    printf("Chaîne : \"%s\" | Caractère : '%c' (code %d)\n", s, (c >= 32 && c <
127) ? c : '?', c);

    if (ret_real)
        printf("strchr     -> \"%s\"\n", ret_real);
    else
        printf("strchr     -> NULL\n");

    if (ret_ft)
        printf("ft_strchr  -> \"%s\"\n", ret_ft);
    else
        printf("ft_strchr  -> NULL\n");

    printf("\n");
}

void data_strchr()
{
    test_strchr("Caractère présent (simple)", "Hello", 'e');
    test_strchr("Plusieurs occurrences", "Hello", 'l');
    test_strchr("Caractère absent", "Hello", 'z');
    test_strchr("Recherche du '\\0'", "Hello", '\0');
    test_strchr("Chaîne vide", "", 'a');
    test_strchr("Chaîne vide + '\\0'", "", '\0');
    test_strchr("Caractère non imprimable", "ABC", 0);
    test_strchr("Caractère au début", "Hello", 'H');
}
void test_strncmp(const char *label, const char *s1, const char *s2, size_t n)
{
    int real = strncmp(s1, s2, n);
    int mine = ft_strncmp(s1, s2, n);

    printf("---- %s ----\n", label);
    printf("s1 = \"%s\" | s2 = \"%s\" | n = %zu\n", s1, s2, n);
    printf("strncmp     -> %d\n", real);
    printf("ft_strncmp  -> %d\n", mine);

    // Pour simplifier la comparaison du résultat (même signe)
    if ((real == 0 && mine == 0)
        || (real < 0 && mine < 0)
        || (real > 0 && mine > 0))
        printf("✅ Résultat cohérent\n");
    else
        printf("❌ Différence détectée !\n");

    printf("\n");
}

void	data_ft_strncmp()
{
        test_strncmp("Identiques", "Hello", "Hello", 5);
    test_strncmp("Diffère au 4e", "Hello", "Help", 4);
    test_strncmp("Diffère au 4e limité à 3", "Hello", "Help", 3);
    test_strncmp("s1 plus long", "Hello", "Hel", 5);
    test_strncmp("s2 plus long", "Hel", "Hello", 5);
    test_strncmp("Majuscules/minuscules", "abc", "Abc", 3);
    test_strncmp("n = 0", "abc", "xyz", 0);
    test_strncmp("Différence en dernier", "abcd", "abce", 4);
    test_strncmp("Comparaison vide", "", "", 3);
    test_strncmp("Chaîne vide vs non vide", "", "abc", 3);
    test_strncmp("Non vide vs vide", "abc", "", 3);
}

void print_result(const void *real, const void *mine, const char *data)
{
    if (real == NULL && mine == NULL)
        printf("✅ NULL identique\n");
    else if (real == NULL || mine == NULL)
        printf("❌ L’un est NULL, l’autre non\n");
    else
    {
        size_t offset_real = (const unsigned char *)real - (const unsigned char
*)data; size_t offset_mine = (const unsigned char *)mine - (const unsigned char
*)data; printf("strchr offset = %zu | ft offset = %zu -> %s\n", offset_real,
offset_mine, offset_real == offset_mine ? "✅" : "❌");
    }
}

void test_memchr(const char *label, const char *s, int c, size_t n)
{
    const void *real = memchr(s, c, n);
    const void *mine = ft_memchr(s, c, n);

    printf("---- %s ----\n", label);
    printf("Chaîne : ");
    for (size_t i = 0; i < n; i++)
    {
        unsigned char ch = ((unsigned char *)s)[i];
        if (ch >= 32 && ch < 127)
            printf("%c", ch);
        else
            printf(".");
    }
    printf(" | c = '%c' (%d) | n = %zu\n", (c >= 32 && c < 127) ? c : '.', c,
n);

    print_result(real, mine, s);
    printf("\n");
}

void	data_test_ft_memchr()
{
    test_memchr("Caractère présent", "Hello", 'e', 5);
    test_memchr("Caractère absent", "Hello", 'z', 5);
    test_memchr("Caractère au début", "Hello", 'H', 5);
    test_memchr("Caractère à la fin", "Hello", 'o', 5);
    test_memchr("Caractère après \\0", "He\0llo", 'l', 5);
    test_memchr("n = 0", "Hello", 'H', 0);
    test_memchr("Multiples occurrences", "abcabc", 'b', 6);
    test_memchr("Octet non imprimable", "AB\xFF", 0xFF, 5);
}
void test_memcmp(const char *label, const void *s1, const void *s2, size_t n)
{
    int real = memcmp(s1, s2, n);
    int mine = ft_memcmp(s1, s2, n);

    printf("---- %s ----\n", label);
    printf("n = %zu\n", n);
    printf("memcmp     -> %d\n", real);
    printf("ft_memcmp  -> %d\n", mine);

    if ((real == 0 && mine == 0)
        || (real < 0 && mine < 0)
        || (real > 0 && mine > 0))
        printf("✅ Résultat cohérent\n");
    else
        printf("❌ Différence détectée !\n");

    printf("\n");
}

void data_test_ft_memcmp()
{
        test_memcmp("Identiques", "abc", "abc", 3);
    test_memcmp("Diff au 3e", "abc", "abd", 3);
    test_memcmp("Diff au 1er", "xbc", "abc", 3);
    test_memcmp("Limite au 3e", "abc", "abd", 2);
    test_memcmp("Avec \\0 au milieu", "ab\0c", "ab\0d", 4);
    test_memcmp("Diff après \\0", "abc\0xx", "abc\0yy", 6);
    test_memcmp("n = 0", "test", "fail", 0);
    test_memcmp("Valeurs signées (unsigned test)", "AB", "A\xFF", 2);
}

*/
void test_strnstr(const char *label, const char *s1, const char *s2, size_t n) {
  char *real = strnstr(s1, s2, n);
  char *mine = ft_strnstr(s1, s2, n);

  printf("---- %s ----\n", label);
  printf("s1 = \"%s\" | s2 = \"%s\" | n = %zu\n", s1, s2, n);
  printf("strnstr     -> %s\n", real ? real : "(NULL)");
  printf("ft_strnstr  -> %s\n", mine ? mine : "(NULL)");

if ((real == NULL && mine == NULL)
    || (real && mine && ft_strncmp(real, mine, ft_strlen(real)) == 0))
    printf("✅ Résultat cohérent\n");
else
    printf("❌ Différence détectée !\n");
  printf("\n");
}

void data_strnstr() {
  test_strnstr("Sous chaine presente au debut", "Hello World", "Hello", 11);
  test_strnstr("Sous chaine presente au milieu", "Hello World", "lo Wo", 11);
  test_strnstr("Sous chaine presente mais apres size", "Hello World", "Word", 5);
  test_strnstr("Sous chaine abs", "Hello", "abc", 5);
  test_strnstr("needle vide", "Hello", "", 5);
  test_strnstr("haystack vide", "", "a", 5);
  test_strnstr("haystack vide", "", "a", 5);
  test_strnstr("size = 0", "Hello", "HelloWord", 5);
  test_strnstr("needle et haystack identiques", "Hello", "Hello", 5);
  test_strnstr("needle partiellement en fin de size", "abcd", "cd", 3);
}

int main(void) {
  // data_ft_strlcat();
  // test_ft_toupper();
  // test_ft_tolower();
  // data_strchr();
  // data_ft_strncmp();
  // data_test_ft_memchr();
  // data_test_ft_memcmp();
  data_strnstr();
  return (0);
}
