/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:51 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/05 14:31:03 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


static char	*fill_out(const char *s1, const char *s2, size_t lens1,
		size_t lens2)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(lens1 + lens2 + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < lens1)
		out[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < lens2)
		out[j++] = s2[i++];
	out[j] = '\0';
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	out = NULL;
	lens1 = strlen(s1);
	lens2 = strlen(s2);
	out = fill_out(s1, s2, lens1, lens2);
	return (out);
}

char *ft_convert_char_to_binary(unsigned char c)
{
    char    *tmp;
    char    *rev;
    size_t  i;
    int     nbyte;

    tmp = malloc(9);
    if (!tmp)
        return (NULL);
    nbyte = 7;
    i = 0;
    while (nbyte >= 0)
    {
        tmp[i++] = c % 2 + '0';
        c = c / 2;
        nbyte--;
    }
    tmp[i] = '\0';
    rev = malloc(9);
    if (!rev)
        return (NULL);
    nbyte = 0;
    while (i > 0)
        rev[nbyte++] = tmp[--i];
    rev[nbyte] = '\0';
    printf("char b: %s\n", rev);
    return (rev);
}

char    *str_to_binary(char *msg)
{
    char    *binary;
    char    *tmp;
    size_t  i;

    if (!msg)
        return (NULL);
    binary = malloc(strlen(msg) * 8 + 1);
    if (!binary)
        return (NULL);
    i = 0;
    while (msg[i])
    {
        tmp = ft_convert_char_to_binary(msg[i]);
        binary = ft_strjoin(binary, tmp);
        tmp = NULL;
        i++;
    }
    free(tmp);
    return (binary);
}

void handler_client(pid_t pid_server, char *msg)
{
    pid_t pid;
    char    *binary;
    size_t  i;

    pid = getpid();
    printf("PID Client: %d\n", pid);
    printf("Message a envoye: \"%s\"\n", msg);
    printf("pidS: %d\n", pid_server);

    binary = str_to_binary(msg);

    printf("binary: %s\n", binary);
    i = 0;
    while (binary[i])
    {
        if (binary[i] == '0')
        {
            kill((pid_t)pid_server, SIGUSR1);
            usleep(10);
        }
        else if (binary[i] == '1')
        {
            kill((pid_t)pid_server, SIGUSR2);
            usleep(10);
        }
        i++;
    }
    free(binary);
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("Need TWO params only: ./client PID \"message\"\n");
        return (-1);
    }
    handler_client(atoi(av[1]), av[2]);
    return (0);
}
