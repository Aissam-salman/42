/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:51 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/04 18:25:04 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler_client(pid_t pid_server, char *msg)
{
    pid_t pid;

    pid = getpid();
    printf("PID Client: %d\n", pid);
    printf("Message a envoye: \"%s\"\n", msg);
    printf("pidS: %d", pid_server);

    kill((pid_t)pid_server, SIGUSR1);
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
