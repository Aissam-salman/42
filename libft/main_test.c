/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/11 20:30:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
// #include <string.h>
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

// void print_strtrim(const char *label, const char *s1, const char *set, const char *expected)
// {
//     char *res = ft_strtrim(s1, set);
//
//     printf("---------- %s --------------\n", label);
//     printf("s1 = \"%s\" | set = \"%s\" \n", s1 ? s1 : "(NULL)", set ? set : "(NULL)");
//     printf("ft_strtrim  --> \"%s\"\n", res ? res : "(NULL)");
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
// void    test_strtrim()
// {
// 	print_strtrim("Base", "   Hello World   ", " ", "Hello World");
// 	print_strtrim("Tab & newline", "\t\nHello\n\t", "\n\t", "Hello");
// 	print_strtrim("Mixed set", "***Hello***", "*", "Hello");
// 	print_strtrim("Mix debut et fin", "--Hello--World--", "-", "Hello--World");
// 	print_strtrim("No trim", "Hello", " ", "Hello");
// 	print_strtrim("Set empty", "Hello", "", "Hello");
// 	print_strtrim("S1 empty", "", " ", "");
// 	print_strtrim("All trim", "aaaaa", "a", "");
// 	print_strtrim("Cara mix", "abcHelloabc", "abc", "Hello");
// 	print_strtrim("Cara spe", "$$Hell#o$$", "$#", "Hell#o");
// 	print_strtrim("Trim space and tab", "  \tHello\t  ", " \t", "Hello");
// 	print_strtrim("s1 = NULL", NULL, " ", NULL); print_strtrim("set = NULL", "Hello", NULL, NULL);
// 	print_strtrim("Unicode", "ééBonjouré", "é", "Bonjour");
// 	print_strtrim("non printable", "\nHello\t", "\n\t", "Hello");
// 	print_strtrim("set= 'Hello'", "HelloHello", "Hello", "");
// 	print_strtrim("Trim before", "    Hello", " ", "Hello");
// 	print_strtrim("Trim after", "Hello    ", " ", "Hello");
// }

// void print_split(const char *label, const char *s, char c, int size, char **expected)
// {
//     char **res = ft_split(s, c);
//
//     printf("---------- %s --------------\n", label);
//     printf("s = \"%s\" | c = \"%c\" \n", s ? s : "(NULL)", c ? c : 'N');
// 	for (int i = 0; i < size ; i++) {
// 		printf("ft_split [%d] --> \"%s\"\n", i,  res[i] ? res[i] : "(NULL)");
// 	}
// 	for (int i = 0; i < size ; i++) {
// 		printf("expected  [%d] --> \"%s\"\n",i,  expected[i] ? expected[i] : "(NULL)");
// 	}
// 	printf("\n");
//     free(res);
// }
//
// void    test_split()
// {
// 	char *expect[] = {"Hello", "World"};
// 	print_split("Base", "Hello World", ' ', 2,  expect);
// 	char *expect1[] = {"Hello", "World"};
// 	print_split("Base", "   Hello World    ", ' ', 2,  expect1);
// 	char *expect2[] = {"Hello", "World"};
// 	print_split("Tab", "\tHello\tWorld\t", '\t', 2,  expect2);
// 	char *expect3[] = {"He","llo", "World"};
// 	print_split("Mixed set ", "***He*llo**World***", '*', 3,  expect3);
// 	char *expect4[] = {"Hello-World"};
// 	print_split("No split", "Hello-World", ' ', 1,  expect4);
// 	char *expect5[] = {"(NULL)"};
// 	print_split("S empty", "", ' ', 1,  expect5);
// 	char *expect6[] = {"(NULL)"};
// 	print_split("all in delimiter", "aaaa", 'a', 1,  expect6);
// 	char *expect7[] = {"S", "lut c", " v"};
// 	print_split("Cara mix", "Salut ca va", 'a', 3,  expect7);
// 	char *expect8[] = {"Salut", "c*a*v", "a"};
// 	print_split("Cara spe", "Salut#c*a*v#a", '#', 3,  expect8);
// 	char *expect9[] = {"NULL"};
// 	print_split("s = NULL", "NULL", '#', 1,  expect9);
// 	char *expect10[] = {"hello"};
// 	print_split("c = NULL", "hello", '\0', 1,  expect10);
// }

// void print_itoa(const char *label, int n, char *expected)
// {
//     char *res = ft_itoa(n);
//
//     printf("---------- %s --------------\n", label);
//     printf("n = \"%d\" \n", n);
// 	printf("ft_itoa   --> \"%s\"\n", res ? res : "(NULL)");
// 	printf("expected  --> \"%s\"\n", expected ? expected : "(NULL)");
// 	printf("\n");
//     int ok;
//     if (expected == NULL && res == NULL)
//         ok = 1;
//     else if (expected == NULL || res == NULL)
//         ok = 0;
//     else
//         ok = strcmp(res, expected) == 0;
//     printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
// 	printf("\n");
//     free(res);
// }
//
// void	test_itoa()
// {
// 	print_itoa("Base case", 123, "123");
// 	print_itoa("Base case", -12, "-12");
// 	print_itoa("INT_MIN", -2147483648, "-2147483648");
// 	print_itoa("INT_MAX", 2147483647, "2147483647");
// 	print_itoa("Zero", 0, "0");
// }

// char ft_test(unsigned int index, char c)
// {
// 	(void)index;
// 	return (ft_toupper(c));
// }
//
// char ft_same(unsigned int i, char c) {(void)i; return (c);}
// char ft_test_index(unsigned int i, char c) { return (c + i);}
//
// void print_strmapi(const char *label, char const *s, char (*f)(unsigned int, char), char *expected)
// {
//     char *res = ft_strmapi(s, f);
//
//     printf("---------- %s --------------\n", label);
//     printf("s = \"%s\" \n", s);
// 	printf("ft_strmapi   --> \"%s\"\n", res ? res : "(NULL)");
// 	printf("expected  --> \"%s\"\n", expected ? expected : "(NULL)");
// 	printf("\n");
//     int ok;
//     if (expected == NULL && res == NULL)
//         ok = 1;
//     else if (expected == NULL || res == NULL)
//         ok = 0;
//     else
//         ok = strcmp(res, expected) == 0;
//     printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
// 	printf("\n");
//     free(res);
// }
//
// void	test_strmapi()
// {
// 	print_strmapi("Base case", "hello", ft_test, "HELLO");
// 	print_strmapi("Empty S", "", ft_test, "");
// 	print_strmapi("NULL S", NULL, ft_test, NULL);
// 	print_strmapi("NULL f", "hello", NULL, "hello");
// 	print_strmapi("NULL f et S", NULL, NULL, NULL);
// 	print_strmapi("Car spe", "Hello, 42! $$", ft_test, "HELLO, 42! $$");
// 	print_strmapi("Long", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", ft_test, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
// 	print_strmapi("f with same return c", "Hello", ft_same, "Hello");
// 	print_strmapi("f play with index", "Hello", ft_test_index, "Hfnos");
// }

// void	ft_test_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }
//
// void	ft_same(unsigned int i, char *c) {(void)i; (void)c;}
// void	ft_test_index(unsigned int i, char *c) {*c += i;}
//
// void print_striteri(const char *label, char *s, void (*f)(unsigned int, char *), char *expected)
// {
//     printf("---------- %s --------------\n", label);
//     printf("s = \"%s\" \n", s);
// 	printf("BEFORE ft_striteri   --> \"%s\"\n", s ? s : "(NULL)");
// 	ft_striteri((char *)s, f);
// 	printf("AFTER ft_striteri   --> \"%s\"\n", s ? s : "(NULL)");
// 	printf("expected  --> \"%s\"\n", expected ? expected : "(NULL)");
// 	printf("\n");
// 	int ok;
// 	if (expected == NULL && s == NULL)
// 		ok = 1;
// 	else if (expected == NULL || s == NULL)
// 		ok = 0;
// 	else
// 		ok = strcmp(s, expected) == 0;
// 	printf("Result: %s\n\n", ok ? "✅ OK" : "❌ FAIL");
// 	printf("\n");
// 	printf("\n");
// }
//
// void	test_striteri()
// {
// 	char s[] = "Hello";
// 	print_striteri("Base case", s, ft_test_index, "Hfnos");
// 	char s1[] = "Hello";
// 	print_striteri("f play with index", s1, ft_test_upper, "HELLO");
// 	char s2[] = "";
// 	print_striteri("Empty S", s2, ft_test_upper, "");
// 	print_striteri("NULL S", NULL, ft_test_upper, NULL);
// 	char s4[] = "hello";
// 	print_striteri("NULL f", s4, NULL, "hello");
// 	print_striteri("NULL f and S", NULL, NULL, NULL);
// 	char s5[] = "Hello, 42! $$";
// 	print_striteri("Caracter spe", s5, ft_test_upper, "HELLO, 42! $$");
// 	char s6[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
// 	print_striteri("Long", s6, ft_test_upper, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
// 	char s7[] = "Hello";
// 	print_striteri("f with same return c", s7, ft_same, "Hello");
// 	char s8[] = "Hello";
// 	print_striteri("f with same r", s8, ft_same, "Hello");
// }
//
// void	test_putchar_fd()
// {
// 	int pipefd[2];
//     int filefd;
//     char c;
//
//     // 1. Test avec stdout
//     ft_putchar_fd('A', 1); // doit s'afficher à l'écran
//     write(1, "\n", 1);
//
//     // 2. Test avec stderr
//     ft_putchar_fd('B', 2); // doit s'afficher comme message d'erreur
//     write(2, "\n", 1);
//
//     filefd = open("test_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (filefd != -1) {
//         ft_putchar_fd('C', filefd);
//         close(filefd);
//         printf("Vérifie 'test_fd.txt' pour voir 'C'\n");
//     }
//
//     // 4. Test avec un pipe
//     pipe(pipefd);
//     ft_putchar_fd('D', pipefd[1]);
//     read(pipefd[0], &c, 1);
//     printf("Pipe a lu : '%c'\n", c);
//     close(pipefd[0]);
//     close(pipefd[1]);
// }

// void	test_putstr_fd()
// {
// 	int pipefd[2];
//     int filefd;
//     char *str = NULL;
//
//     ft_putstr_fd("Hello", 1); 
//     write(1, "\n", 1);
//
//     ft_putstr_fd("Hello", 2);
//     write(2, "\n", 1);
//
//     filefd = open("test_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (filefd != -1) {
//         ft_putstr_fd("Hello", filefd);
//         close(filefd);
//         printf("Vérifie 'test_fd.txt' pour voir \"Hello\"\n");
//     }
// }
// void	test_putendl_fd()
// {
//     int filefd;
//
//     ft_putendl_fd("Hello", 1); 
//     ft_putendl_fd("Hello", 2); 
//     filefd = open("test_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (filefd != -1) {
//         ft_putendl_fd("Hello", filefd);
//         close(filefd);
//         printf("Vérifie 'test_fd.txt' pour voir \"Hello\"\n");
//     }
// }

// void	test_putnbr_fd()
// {
//     int filefd;
//
//     ft_putnbr_fd(120, 1); 
// 	printf("\n");
//     ft_putnbr_fd(2147483647, 2); 
// 	printf("\n");
//     filefd = open("test_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (filefd != -1) {
//         ft_putnbr_fd(-2147483648, filefd);
//         close(filefd);
//         printf("Vérifie 'test_fd.txt' pour voir \"-2147483648 \"\n");
//     }
// 	printf("\n");
// }
int main(void)
{
    return (0);
}
