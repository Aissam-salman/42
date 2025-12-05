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
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

static char *stash[1000];
static int len = 0;
// char    *convert_binary_to_str(char *msg);

// sig numero de signal envoyer
void signal_callback_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("SIGUSR1: %d\n", sig);
        stash[len++] = "0";
    }
    else if (sig == SIGUSR2)
    {
        printf("SIGUSR2: %d\n", sig);
        stash[len++] = "1";
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    bzero(&sa, sizeof(sa));
    printf("PID Server: %d\n", pid);
    (void) pid;
    sa.sa_handler = &signal_callback_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1);
    return (0);
}
