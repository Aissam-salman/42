/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:41 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/10 15:08:22 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"
#include <stdio.h>


int ft_end(char *stash)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '0')
			count++;
		i++;
	}
	if (count == 7)
		return (1);
	return (0);
}

void signal_callback_handler(int sig)
{
	static char *stash;
	size_t i;

    if (sig == SIGUSR1)
	{
		ft_putchar_fd('0', 1);
        stash = ft_strjoin(stash, "0");
	}
    else if (sig == SIGUSR2)
	{
		ft_putchar_fd('1', 1);
    	stash = ft_strjoin(stash, "1");
	}
	if  (ft_end(stash))
	{
		printf("%s\n", stash);
		i = 0;
		while (1)
		{
			// take 8 bit to make one char 
			char  *c = ft_substr(stash + i, i, 8);
			if (ft_end(c))
				break;
			i += 8;
			int b = ft_atoi_base(c, "01");
			unsigned char character = (unsigned char) b;
			printf("%c", character);
		}
		printf("\n end");
		free(stash);
	}
}


int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    ft_bzero(&sa, sizeof(sa));
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
