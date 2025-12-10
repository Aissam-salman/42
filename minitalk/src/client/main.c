/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:51 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/10 17:48:36 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include <signal.h>
#include <unistd.h>

static char *ft_convert_char_to_binary(unsigned char c)
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
    return (rev);
}

static char    *ft_str_to_binary(char *msg)
{
    char    *binary;
    char    *tmp;
    size_t  i;

    if (!msg)
        return (NULL);
    binary = malloc(ft_strlen(msg) * 8 + 1);
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

void	ft_end_msg(pid_t pid_server)
{
	int 	i;

	i = 0;
	while (i < 8)
	{
		kill(pid_server, SIGUSR1);
		usleep(5);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid_server, SIGUSR2);
		usleep(5);
		i++;
	}
}

void handler_client(pid_t pid_server, char *msg)
{
    pid_t pid;
    char    *binary;
    size_t  i;

    pid = getpid();
    printf("PID Client: %d\n", pid);
    binary = ft_str_to_binary(msg);
    i = 0;
    while (binary[i])
    {
        if (binary[i] == '0')
        {
            kill((pid_t)pid_server, SIGUSR1);
            usleep(5);
        }
        else if (binary[i] == '1')
        {
            kill((pid_t)pid_server, SIGUSR2);
            usleep(5);
        }
        i++;
    }
    free(binary);
	ft_end_msg(pid_server);
}


int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("Need TWO params only: ./client PID \"message\"\n");
        return (-1);
    }
    handler_client(ft_atoi(av[1]), av[2]);
    return (0);
}
