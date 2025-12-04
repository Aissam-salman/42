/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:41 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/04 18:29:10 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
// #include <stdlib.h>
//

void handle_sigusr1(int sig)
{
    printf("from handle sigusr1: %d", sig);
}


void    init_server(void)
{
    pid_t pid;
    struct sigaction sa = {0};
    pid = getpid();
    printf("PID Server: %d\n", pid);

    sa.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    // listen the signals
   // two signals: SIGUSR1 and SIGUSR2.
    // handle it with, printf or other fn
}

int main(void)
{
    init_server();
    return (0);
}
